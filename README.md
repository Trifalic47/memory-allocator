# Allocator

Custom C memory allocator implementation using `sbrk`.

## Overview

`allocator` is a minimal custom memory allocator written in C. It manages process heap memory directly by extending the program break via `sbrk()`.

## Data Structures & State

Defined in `utils.h`:

### `struct heap`
Global instance `HEAP` tracks heap state:
- `hbase` (`void *`): Base address of the heap (recorded at program startup).
- `ploc` (`void *`): Pointer to the start address of the most recent allocation.
- `isfree` (`bool`): Flag indicating heap status.

### `struct free_db` & `struct free_entries`
Data structures defined for tracking freed memory regions:
- `FREE_DB_CAPACITY`: Defined as `1024`.
- `struct free_entries`: Stores `addr` (`void *`) and `size` (`size_t`).
- `struct free_db`: Contains an array of up to 1024 `entries` and `total_entries` count.

### Heap Baseline (`fbreak` & `init_break`)
- `fbreak`: Global const pointer storing initial program break (`sbrk(0)`).
- `init_break()`: Constructor function (`__attribute__((constructor))`) executed before `main()` to initialize `fbreak`.

## API Reference

| Function | Prototype | Description |
| --- | --- | --- |
| `mafoc` | `void *mafoc(size_t size)` | Extends the heap break using `sbrk(size)`, updates `HEAP.ploc`, and returns the memory pointer. Exits if `sbrk` fails. |
| `mafree` | `void mafree(void *ptr)` | Free function (stub / in progress). |

## Building and Running

### Prerequisites
- GCC
- POSIX/Linux environment (requires `<unistd.h>` and `sbrk`)

### Targets

- **Build binary (`./alloc`)**:
  ```sh
  make
  ```
  *Compiles `./alloc.c` and `./utils.c` with flags `-g -O0 -Wall -Wextra -fsanitize=address`.*

- **Run binary**:
  ```sh
  make run
  ```

- **Clean executable**:
  ```sh
  make clean
  ```

## Current Project Status

- [x] Initial program break baseline capture (`init_break`)
- [x] Basic memory allocation via `sbrk` (`mafoc`)
- [ ] Memory deallocation (`mafree`)
- [ ] Reuse/free memory tracking (`struct free_db`)
