# Sorting Visualizer

An interactive C++ application that visualizes sorting algorithms in real time using **SFML**.  
This project highlights algorithmic knowledge and graphics programming — making it both educational and technically impressive.

---

## 🔑 Key Features
- Visualizations for Bubble Sort, Insertion Sort, Selection Sort
- Real‑time animations with SFML graphics

---

## 📂 Project Structure
Sorting-Visualizer/
│
├── Code/
│   ├── Main.cpp         # Application entry point
│   ├── sorting.cpp      # Algorithm implementations
│   ├── sorting.h        # Algorithm declarations
│   ├── measure.h        # Performance measurement utilities
│
├── CMakeLists.txt       # Build configuration
├── .gitignore           # Ignore build artifacts and IDE configs

Code

---

## ⚙️ Requirements
- C++17 or later  
- CMake 3.10+  
- SFML 3.1.0 (system, window, graphics, audio, network)

---

## 🚀 Build & Run
```bash
# Clone the repository
git clone https://github.com/sharrkyy/Sorting-Visualizer.git
cd Sorting-Visualizer

# Create build directory
mkdir build && cd build

# Configure project
cmake ..

# Build executable
cmake --build .

# Run
./sorting-app
