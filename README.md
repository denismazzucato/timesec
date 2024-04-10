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

## Evaluation

To reproduce the claims made in the paper, you can run the following commands:

- SV benchmarks, Table 3 and 4: `./sv`
- Bignum benchmarks, Table 5: `./bignum`


### Benchmarks

The benchmarks are located in the `benchmarks` directory:
- `s2n-bignum`: disassembled code from the cryptographic library [s2n-bignum](https://github.com/awslabs/s2n-bignum)
- `sv-benchmarks/termination-crafted`: benchmarks from the 13th Software Verification Competition [SV-COMP](https://sv-comp.sosy-lab.org/2024/), category `termination`
- `sv-benchmarks/termination-crafted-lit`: benchmarks from the 13th Software Verification Competition [SV-COMP](https://sv-comp.sosy-lab.org/2024/), category `termination`

## Usage outside the benchmarks

To show the help message, run:

```bash
python timesec.py --help
```

To run the tool, for example on the bignum benchmark, run:

```bash
python timesec.py benchmarks/s2n-bignum
```

Try to add your own function `custom` in the `examples/example.c` file and run the tool with the `--verbose --debug 2` option to see the intermediate results and verbose log:

```bash
python timesec.py examples/example.c --verbose --debug 2 --function custom
```

### Project Structure

- `timesec.py`: main entry point of the tool
- `README.md`: this file
- `Dockerfile`: docker file
- `environment.yml`: conda environment file
- `requirements.dev`: file containing the development requirements
- `LICENSE`: file containing the license
- `.gitignore`: file containing the gitignore rules
- `.pylintrc`: file containing the pylint rules
- `bignum`: script to run the bignum benchmarks
- `sv`: script to run the sv benchmarks
- `src`: directory containing the source code
- `benchmarks`: directory containing the benchmarks
- `examples`: directory containing crafted C programs
- `scripts`: directory containing scripts to help with the development
- `tables`: directory containing the scripts to generate the tables and the tables themselves
