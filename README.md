# cli-calcu

A CLI calculator that evaluates math expressions with proper operator precedence.

## Features
- Basic arithmetic: `+`, `-`, `*`, `/`
- Parentheses support: `(2+3)*4`
- Decimal numbers: `1200*40.4`
- Continuous input loop

## Build
```bash
g++ -std=c++20 -Wall cli-calcu_proto.cpp -o cli-calcu
```

## Usage
```bash
./cli-calcu
>> 2+3*4
14
```

## Planned
- Exponent support `^`
- `sqrt()`, `sin()`, `cos()`
- Error handling for invalid input
- Install as system command
