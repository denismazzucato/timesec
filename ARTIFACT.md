# TimeSec

[![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.11127584.svg)](https://doi.org/10.5281/zenodo.11127584)

Artifact documentation for the paper "Quantitative Static Timing Analysis" submitted to SAS 2024. Here we provide the instructions to reproduce the results presented in the paper, namely Table 4 and 5 in Section 7 "Evaluation" (and optionally Table 6 and 7 in Appendix C "SV-Comp Benchmarks").

The artifact is a docker image containing the *TimeSec* tool, the benchmarks, and the evaluation scripts. The docker image is available on [https://zenodo.org/10.5281/zenodo.11127584](https://doi.org/10.5281/zenodo.11127584).
The artifact has been tested on a ubuntu low-end machine.

## Kick-the-Tires (<4 minutes)

Load and enter the provided docker image (<1 min):

```bash
docker load < timesec.tar
docker run -it timesec /bin/bash
```

Run the evaluation on the [s2n-bignum](https://github.com/awslabs/s2n-bignum) library (<3 min):
```bash
./bignum
```

After executing the analysis for all the programs of the s2n-bignum library, the tool outputs the results in the console and generates a pdf file, containing Table 4 of Section 7 of the paper. The pdf file is located at `tables/timesec.pdf`.

> Note that, the program `bignum_modexp.c` is expected to fail due to the lack of function calls' support.

Exit the container:
```bash
exit
```
and copy the pdf `tables/timesec.pdf` to the host machine to compare the obtained results with the ones presented in the paper (Table 4 of Section 7):
```bash
docker cp $(docker ps -l -q):/timesec/tables/timesec.pdf .
```
where `docker ps -l -q` returns the container id of the last executed container.

The pdf file `timesec.pdf` in the current directory contains Table 4 of Section 7 of the paper. The table should be identical to the one presented in the paper.


## Available Badge
The tool is available on Zenodo: [https://zenodo.org/10.5281/zenodo.11127584](https://doi.org/10.5281/zenodo.11127584).

## Functional Badge (~30 minutes)

If already loaded the docker image in the previous step skip this command, otherwise load the provided docker image with (<1 min):

```bash
docker load < timesec.tar
```

Enter the loaded docker image (<1 min):

```bash
docker run -it timesec /bin/bash
```

Run the full evaluation on the s2n-bignum library (Table 4 and 5 of Section 7) and on the SV-COMP benchmarks (Table 6 and 7 of Appendix C) (~30 min):
```bash
./all
```
Otherwise, you can skip the benchmarks of Appendix C by running only the evaluation on the s2n-bignum library using the script (~10 min)
```bash
./ablation
```

When finished, copy the generated pdf to the host machine:
```bash
docker cp $(docker ps -l -q):/timesec/tables/timesec.pdf .
```

The file `timesec.pdf` in the current directory contains the tables shown in the paper's evaluation. Depending on which script you ran, the tables will be different:
- `./bignum` shows Table 4 (kick-the-tires).
- `./ablation` shows Tables 4 and 5.
- `./all` shows Tables 4, 5, 6, and 7.

It is important to check the following points in `timesec.pdf`:
- Table 4:
  No numerical variable should be maybe dangerous: all the variables listed under the "maybe dangerous" column should start with the letter "s" and be highlighted in green.
- Table 5:
  - The number of variables listed under the "maybe dangerous" column should decrease as we add the optimizations of *TimeSec*.
  - The analysis time should increase as we add the optimizations of *TimeSec*.
- Table 6:
  The analysis time should follow the same trend as the one presented in the paper.
- Table 7:
  The quantities reported in the table should identical to the ones presented in the paper.

## Reusable Badge

To evaluate the reusability of *TimeSec* we propose three ways: (1) check the helper menu, (2) run the tool on a custom function, (3) look at the project structure, source code, and documentation.

### (1) Check the helper menu

Load and enter the provided docker image:

```bash
docker load < timesec.tar
docker run -it timesec /bin/bash
```

Check the helper menu:
```bash
python timesec.py --help
```

### (2) Try it out

Try to run *TimeSec* on a custom function.
For example, let's build a function called `custom` with two input arguments *x* and *y*, where *x* has an impact on the number of loop iterations that is greater that the one of *t*, eg:
```
void custom(int x, int y){
  int i = 0;
  while (i < 2 * x + y) {
    i = i - 1;
  }
}
```
As you can notice, the number of loop iterations depends more on *x* than on *y*.

> If you customize the example, please note that we do not support the full C standard.

Store this function in a c file:
```bash
touch example.c && echo "
void custom(int x, int y){
  int i = 0;
  while (i < 2 * x + y) {
    i = i + 1;
  }
}
" >> example.c
```

Check the content of the newly created `example.c`:
```bash
cat example.c
```

It can be interesting to study such program with a bounded input space, eg. [0, 10] for both *x* and *y*:
```bash
python timesec.py example.c --function custom --input-bounds 0 10
```
> Additionally, add `--debug 1` to increase the verbosity level and get more information about the result of the syntactic analysis, the generated program invariant, and tool flags.

And this should be the expected output (without the debug flag):
```
Analysis Results: (parse: 0.05s, points_to_analysis: 0.00s, dependency_analysis: 0.00s, fixpoint_iterator: 0.03s, impact_analysis: 0.01s)

    Variable    Type    Usage     Impact    Notes
--  ----------  ------  --------  --------  ------------------
 0  x           Input   May Used  20        Possibly Dangerous
 1  y           Input   May Used  10        Possibly Dangerous
 2  i           Local   Unused    0         Definitely Safe
```
As a result, *TimeSec* reports that the input variable *x* has an impact greater than the one of *y* on the number of loop iterations as expected. Moreover, we show that the initial value of the local variable *i* does not influence the number of loop iterations as it is initialized to 0 at the beginning.


### (3) Source code and documentation

The project is organized as follows:

- `timesec.py`: main entry point of the tool
- `README.md`: How to install and entry point of the tool
- `environment.yml`: conda environment file
- `LICENSE.md`: license file
- `.gitignore`: file containing the gitignore rules
- `.pylintrc`: file containing the pylint rules
- `src`: directory containing the source code
- `benchmarks`: directory containing the benchmarks
- `examples`: directory containing crafted C programs

The python source code is modular and well-structured as expected for a static analysis tool. We design *TimeSec* with extensibility in mind, allowing the user to easily add new abstract domains, analysis stages, or new impact definitions. The source code is annotated with type hints to make it more robust and docstrings for documentation purposes.
During the computation, increasing the verbosity level will provide more information about the analysis stages and the obtained results.
The documentation on how to install *TimeSec* is available in the `README.md` file
The tool is distributed under the MIT license, see `LICENSE.md` for more information.

The main entrance point is `src/main.py` for both single file analysis and benchmark mode. The source code is organized as follows (within the `src` directory):
- `main.py`: entry point of the source code, the function `single_run` contains the main logic of the tool
- `impact.py`: quantification of the impact given the generated program invariant
- `abstract_domains` directory, contains the abstract domains used for the forward/backward analyses:
  - `polka.py`: implementation of the Polyhedra abstract domain
  - `polka_with_streams.py`: implementation of the Polyhedra abstract domain with custom handler for input stream variables
  - `syntactic_dependencies` directory: contains the abstract domain of syntactic dependencies
- `engine` directory, contains the analysis engines:
  - `fixpoint.py`: implementation of the fixpoint iterator (both forward and backward, depending on the analysis direction parameter)
  - `dependency_analysis.py`: engine for the dependency analysis
  - `points_to_analysis.py`: engine for the points-to analysis
- `proto` directory, contains the protocol for poset/lattice structures
- `frontend` directory, contains the frontend for the C language, from parsing to extracting the abstract syntax tree and symbolic expressions
- `utils` directory, contains utility functions
- `user_interface` directory, contains the functions to interface with the user

## Artifact Notes


This artifact has been compiled with `docker build -t timesec .` (~15 min) in a linux machine and saved with `docker save timesec > timesec.tar` (~1 min).
