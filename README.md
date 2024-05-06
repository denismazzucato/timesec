# TimeSec

## TLDR; for the artifact evaluation

### Kick-the-Tires (~4 minutes)

Load the provided docker image:

```bash
docker load timesec.tar
```

Run the evaluation on the [s2n-bignum](https://github.com/awslabs/s2n-bignum) library (about 2 min):
```bash
docker run timesec
```

When finished, copy the generated pdf (`tables/tables.pdf`) to the host machine to compare the obtained results with the ones presented in the paper (Table 4):
```bash
docker cp timesec:timesec/tables/tables.pdf .
```


### Available Badge
The tool is available in Zenodo:

### Functional Badge (~20 minutes)

Load the provided docker image:

```bash
docker load timesec.tar
```
Run all the benchmarks (about 20 min):
```bash
docker run -it timesec ./all
```

When finished, copy the generated pdf to the host machine:
```bash
docker copy timesec:/tables/tables.pdf .
```

The pdf file `tables.pdf` in the current directory contains the tables shown in the paper's evaluation.
Please, check that:
- Table 4:
  - The Quantities of Table 3 of your evaluation should be identical of quantities in the one presented in the paper.
  - Regarding the analysis time, the INV analysis time is the most expensive part of the analysis.
- Table 5:
  - The Table 4 of your evaluation should be identical of the one presented in the paper.
- Table 6:
  - The "VARIABLES" of Table 5 of your evaluation should be identical of the "VARIABLES" in the one presented in the paper.
  - INV should take most of the time without DEPS nad have small variability (STD after ± in the TOT column). Without OPTS, DEPS should take most time and LP should be close to zero. With FULL, INV should be bigger than DEPS and LP close to zero.

### Reusable Badge

Enter the container with a terminal:
```bash
...
```

Check the helper menu:
```bash
python timesec.py --help
```

Try to run our tool on a custom function.
For example, let's build a function `custom` with two input arguments x and y, where x has a double impact on the number of loop iterations, eg:
```
void custom(int x, int y){
  int i = 0;
  while (i < 2 * x + y) {
    i = i - 1;
  }
}
```
If you customize the example, please note that we do not support the full C standard. Then store this function in a c file:
```bash
touch example.c && echo "
void custom(int x, int y){
  int i = 0;
  while (i < 2 * x + y) {
    i = i - 1;
  }
}
" >> example.c
```

Try it out:
```bash
python timesec.py example.c --function-name custom
```

And this should be the expected output:
```
...
```



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
