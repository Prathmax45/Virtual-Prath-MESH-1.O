This is the level 2 of the previous virtual 8-bit computer....
It involves the data communication between the virtual computer forming a network 
hence named as "mesh".

# 🧠 Virtual Prath-MESH 1.0 — A Dual-CPU Virtual Machine with Inter-Thread Communication

> A second-year C project that simulates two communicating CPUs using threads, custom instruction sets, and binary programs.

---

## 🚀 Project Overview

**Virtual Prath-MESH 1.0** is a multi-threaded virtual computing environment where two CPUs execute independent `.rvm` binaries and communicate via shared memory using custom opcodes (`TRF`, `RCV`). Each CPU runs in its own thread and interprets instructions loaded from compiled assembly-like programs.

---

## 🧩 Features

- 🧠 **Custom Instruction Set**: Includes basic operations (`ADD`, `SUB`, `MUL`, etc.) and I/O (`INP_A`, `INP_B`, `PRN`)
- 🔄 **TRF/RCV Opcodes**: Transfer data between CPUs in a synchronized manner
- 🧵 **Multi-threaded Execution**: Uses `pthread` for real-time, parallel CPU simulation
- 🧾 **Assembler**: Converts `.rvm` instructions into `.bin` binary memory files
- 📂 **Modular Codebase**: Separated into CPU logic, execution core, shared memory, and assembly compiler

---




