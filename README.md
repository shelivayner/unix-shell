# unix-shell

**unix-shell** is an educational Unix shell written in C. It is a teaching project for parsing command lines, spawning processes, and wiring up classic shell features.

## Planned features

- Command-line tokenizer
- Parser for simple commands
- External command execution
- Pipes (`|`)
- I/O redirection (`<`, `>`, `>>`)
- Signal handling (for example Ctrl-C)

## Build

```sh
make
./unix-shell
```

Run tokenizer tests:

```sh
make test
```
