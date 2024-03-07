# TimeSec

##  Install

We require [conda](https://docs.conda.io/en/latest/miniconda.html) and [apron](https://antoinemine.github.io/Apron/doc/) to be installed.
Otherwise, you can install the dependencies with the following command:

```bash
wget https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh
bash Miniconda3-latest-Linux-x86_64.sh -b
rm -f Miniconda3-latest-Linux-x86_64.sh
conda --version
```

```bash
apt-get install opam
opam init
opam install apron
```

Then, clone this repository and install the dependencies from `environment.yml`:

```bash
conda env create -f environment.yml
conda activate timesec
```

### Docker

You can also use the provided Dockerfile to build a docker image of timesec:

```bash
docker build -t timesec .
```

Then, you can access the image with:

```bash
docker run -it timesec
```

## Usage

To show the help message, run:

```bash
python timesec.py --help
```

To run the tool, for example on the bignum benchmark, run:

```bash
python timesec.py benchmarks/bignum
```

## Benchmarks

The benchmarks are located in the `benchmarks` directory:
- `bignum`: disassembled code from the cryptographic library [s2n-bignum](https://github.com/awslabs/s2n-bignum)
- `sv-benchmarks/termination-crafted`: benchmarks from the 13th Software Verification Competition [SV-COMP](https://sv-comp.sosy-lab.org/2024/), category `termination`
- `sv-benchmarks/termination-crafted-lit`: benchmarks from the 13th Software Verification Competition [SV-COMP](https://sv-comp.sosy-lab.org/2024/), category `termination`
- `sv-benchmarks/termination-15`: benchmarks from the 15th Software Verification Competition [SV-COMP](https://sv-comp.sosy-lab.org/2026/), category `termination`

## Project Structure

- `timesec.py`: main entry point of the tool
- `README.md`: this file
- `Dockerfile`: docker file
- `environment.yml`: conda environment file
- `requirements.dev`: file containing the development requirements
- `TODO.md`: file containing the TODO list
- `LICENSE`: file containing the license
- `.gitignore`: file containing the gitignore rules
- `.pylintrc`: file containing the pylint rules
- `src`: directory containing the source code
- `benchmarks`: directory containing the benchmarks
- `examples`: directory containing crafted C programs
- `scripts`: directory containing scripts to help with the development
