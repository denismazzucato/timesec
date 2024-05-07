# TimeSec

## Kick-the-Tires (~4 minutes)

Load the provided docker image (~1 min):

```bash
docker load < timesec.tar
```

Run the evaluation on the [s2n-bignum](https://github.com/awslabs/s2n-bignum) library (~2 min):
```bash
docker run timesec
```

When finished, copy the generated pdf (`tables/timesec.pdf`) to the host machine to compare the obtained results with the ones presented in the paper (Table 4):
```bash
docker cp timesec:/timesec/tables/timesec.pdf .
```


## Available Badge
The tool is available on Zenodo:

## Functional Badge (~20 minutes)

Load the provided docker image (~2 min):

```bash
docker load < timesec.tar
```
Run all the benchmarks (~20 min):
```bash
docker run -it timesec ./all
```
Otherwise, you can skip the benchmarks on the SV-COMP provided in the appendix of the paper and run only the ablation study to create both tables of Section 7:
```bash
docker run -it timesec ./ablation
```

When finished, copy the generated pdf to the host machine:
```bash
docker copy timesec:/timesec/tables/timesec.pdf .
```

The pdf file `tables.pdf` in the current directory contains the tables shown in the paper's evaluation. Depending on which script you ran, the tables will be different. In particular:
- `docker run -it timesec ./bignum` shows Table 4.
- `docker run -it timesec ./ablation` shows Tables 4 and 5.
- `docker run -it timesec ./all` shows Tables 4, 5, 6, and 7.

Please, it is important to check the following points in the generated pdf file:
- Table 4:
  No numerical variable should be maybe dangerous: all the variables listed under the "maybe dangerous" column should start with the letter "s" and be highlighted in green.
- Table 5:
  - The variables listed under the "maybe dangerous" column should decrease by restoring the analyses and optimizations of TimeSec.
  - The analysis time should increase by restoring the analyses and optimizations of TimeSec.
- Table 6:
  The analysis time should follow the same trend as the one presented in the paper.
- Table 7:
  The quantities reported in the table should identical to the ones presented in the paper.

## Reusable Badge

To evaluate the reusability of TimeSec we propose three ways: (1) check the helper menu, (2) run the tool on a custom function, (3) look at the project structure, source code, and documentation.

### (1) Check the helper menu

Enter the container with a terminal:
```bash
...
```

Check the helper menu:
```bash
python timesec.py --help
```

### (2) Try it out

Try to run TimeSec on a custom function.
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

The python source code is modular and well-structured as expected for a static analysis tool. We design TimeSec with extensibility in mind, allowing the user to easily add new abstract domains, analysis stages, or new impact definitions. The source code is annotated with type hints to make it more robust and docstrings for documentation purposes.
During the computation, increasing the verbosity level will provide more information about the analysis stages and the obtained results.
The documentation on how to install TimeSec is available in the `README.md` file
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
