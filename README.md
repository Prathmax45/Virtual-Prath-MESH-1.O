This is the level 2 of the previous virtual 8-bit computer....
It involves the data communication between the virtual computer forming a network 
hence named as "mesh".


# 💻 Virtual Prath-MESH 1.0

**Virtual Prath-MESH 1.0** is a dual-threaded virtual CPU mesh system built in C. It features two simulated CPUs (`cpu_1` and `cpu_2`) running concurrently, sharing memory and communicating using custom-defined opcodes like `TRF` (transfer) and `RCV` (receive). This project demonstrates inter-CPU communication, basic instruction execution, and binary-level program execution — all running in parallel using POSIX threads.

---

## 🚀 Features

- 🧠 Simulated dual CPU environment
- 🧾 Custom instruction set architecture (ISA)
- 🔁 Shared memory communication using `TRF` and `RCV`
- ⚙️ Threading support via `pthread`
- 🛠️ Assembler to convert `.rvm` files into binary `.bin`
- 📦 Modular architecture (CPU logic, assembler, shared memory, execution core)

---

## 📁 File Structure

```
Virtual Prath-MESH 1.0/
│
├── main.c              # 🚀 Launches both CPUs using threads
├── cpu_1.c             # 🧠 CPU 1 logic and memory execution
├── cpu_2.c             # 🧠 CPU 2 logic and memory execution
├── lib.c               # 🔁 Core execution logic (opcodes)
├── lib.h               # 📘 Opcode definitions & function declarations
├── shared_memory.c     # 🔄 Shared memory logic for TRF/RCV
├── shared_memory.h     # 📘 Extern declarations & pthread mutex
├── assembler.c         # 🛠️  Assembler: Converts .rvm to .bin
│
├── cpu_1.rvm           # 📝 Assembly program for CPU 1
├── cpu_1.bin           # 💾 Compiled binary for CPU 1
├── cpu_2.rvm           # 📝 Assembly program for CPU 2
├── cpu_2.bin           # 💾 Compiled binary for CPU 2
│
├── mesh.exe            # ⚙️  Final compiled executable
└── README.md           # 📄 Project description and usage guide
```

---

## ⚙️ Compilation

Make sure you have a `gcc` compiler with `pthread` support (POSIX threads).

```bash
gcc main.c cpu_1.c cpu_2.c lib.c shared_memory.c -o mesh.exe -lpthread
```

---

## 🛠️ Assembling `.rvm` files

Before running the mesh, assemble `.rvm` assembly source code into `.bin` binaries:

```bash
gcc assembler.c -o ast.exe
ast.exe cpu_1.rvm cpu_1.bin
ast.exe cpu_2.rvm cpu_2.bin
```

---

## ▶️ Running the Simulator

After building and assembling:

```bash
mesh.exe
```

You will see CPU1 and CPU2 run concurrently, possibly sharing or transferring data depending on the `.rvm` programs.

---

## 📘 Supported Instructions (Opcodes)

| Opcode   | Description                |
|----------|----------------------------|
| `HLT`    | Halt execution             |
| `LA`     | Load value into register A |
| `LB`     | Load value into register B |
| `ADD`    | Add A and B, store in A    |
| `SUB`    | Subtract B from A          |
| `MUL`    | Multiply A and B           |
| `INP_A`  | Input to register A        |
| `INP_B`  | Input to register B        |
| `PRN`    | Print register A           |
| `TRF`    | Transfer A to other CPU    |
| `RCV`    | Receive into A from other CPU |
| `JMP`    | Unconditional jump         |
| `JZ`     | Jump if A == 1             |

---

## 🧠 Concepts Used

- Threading using `pthread_create`, `pthread_join`, `pthread_mutex_t`
- Memory-mapped execution
- Custom virtual instruction processing
- Modular file separation for maintainability
- Binary file handling and assembler design

---

## 👤 Author

**Prathmesh Satish Kanure**  
`Creator of Virtual Prath-MESH 1.0`  
Passionate about low-level systems, CPU simulation, and pushing the boundaries of C programming.

---



