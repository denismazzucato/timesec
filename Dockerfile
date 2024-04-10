FROM --platform=linux/amd64 ubuntu:20.04

ENV APT_DEPS build-essential opam ocaml clang git pkg-config libgmp-dev \
             libmpfr-dev llvm-10-dev libclang-10-dev libclang-cpp10-dev \
             clang-10 rsync m4 curl wget less ca-certificates

ENV OPAM_DEPS apron

ENV PATH="/root/miniconda3/bin:${PATH}"
ARG PATH="/root/miniconda3/bin:${PATH}"

ARG DEBIAN_FRONTEND=noninteractive

ENV TERM xterm-256color

RUN \
    apt-get update && \
    apt-get install --no-install-recommends -y $APT_DEPS && \
    rm -rf /var/lib/apt/lists/*

RUN apt-get update && apt-get install -y $APT_DEPS

RUN wget \
    https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh \
    && mkdir /root/.conda \
    && bash Miniconda3-latest-Linux-x86_64.sh -b \
    && rm -f Miniconda3-latest-Linux-x86_64.sh
RUN conda --version

RUN opam init --auto-setup --disable-sandboxing
RUN opam install -y $OPAM_DEPS

ENV PYTHONUNBUFFERED 1
ENV APRON_LD_PATH=/root/.opam/default/share/apron/lib/

WORKDIR /app

COPY . /app

ENV CONDAENV timesec

RUN conda env create -n $CONDAENV -f environment.yml && \
    conda init bash && \
    echo "conda activate $CONDAENV" >> ~/.bashrc && \
    conda clean --all --yes

RUN apt-get install -y --no-install-recommends texlive-latex-recommended texlive-fonts-recommended && \
    apt-get install -y --no-install-recommends texlive-latex-extra texlive-fonts-extra texlive-lang-all && \
    rm -rf /var/lib/apt/lists/*

SHELL ["conda", "run", "--no-capture-output", "-n", "$CONDAENV", "/bin/bash", "-c"]

# CMD ["conda", "run", "--no-capture-output", "-n", "myenv", "python", "your_script.py"]
