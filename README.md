# 🎮 TinyGames

**TinyGames** is a collection of mini-games written in modern C++ using modular design, unit testing with GoogleTest, and built with CMake.  
Each game is encapsulated in its own library.  

Currently included:
- 🎲 Dice (random die roll simulator)
- ✊✋✌️ Shifumi (Rock-Paper-Scissors)

---

## 🧱 Project Structure
```
TinyGames/
├── CMakeLists.txt                      # Root CMake
├── app/
│   ├── CMakeLists.txt                  # Builds main.cpp
│   └── main.cpp                        # Entry point
├── lib/
│   ├── CMakeLists.txt 
│   ├── Dice/
│   │   ├── CMakeLists.txt
│   │   ├── Dice.cpp
│   │   ├── Dice.h
│   │   └── test/
│   │       ├── CMakeLists.txt
│   │       └── test_Dice.cpp
│   ├── Shifumi/
│   │   ├── CMakeLists.txt
│   │   ├── Shifumi.cpp
│   │   ├── Shifumi.h
│   │   ├── ShifumiUtils.h
│   │   └── test/
│   │       ├── CMakeLists.txt
│   │       └── test_Shifumi.cpp
```

Each module is built as a static library (`STATIC`) and has its own test executable.

---

## 🧪 Unit Testing

Tests are written using **GoogleTest** and integrated via **CMake FetchContent**.

### 🔧 Run all tests:

```bash
cmake -S . -B build
cmake --build build
cd build
ctest --output-on-failure

Or run individual test binaries:

./lib/Dice/test/testDice
./lib/Shifumi/test/testShifumi

📦 Dependencies

    CMake ≥ 3.14

    GoogleTest (via FetchContent)

    A C++17-compatible compiler

🕹️ Available Games:

🎲 Dice

    Set the number of faces (setDieFaces)

    Roll a die randomly between 1 and n (roll)

    Handles input and usage errors (e.g. invalid face count)

✊✋✌️ Shifumi

    Compares the player's choice against a randomly generated computer choice

    Returns win/loss/tie result

    Outputs a clear message (e.g. "Player wins with Rock against Scissors")

🚀 Future Plans

    🧠 Add a "predictive AI" mode for Shifumi

    📈 Implement score tracking over multiple rounds

    🖥️ Create a unified console interface to select and play games

    ➕ Add more games: Battleship, Tic-Tac-Toe, etc.

👤 Author

Developed by Adrien Walczak as a personal C++ project focused on clean design, testing, and code modularity.

## 📜 License

This project is licensed under the [MIT License](LICENSE).  
You are free to use, modify, distribute, or sell the software,  
as long as the original copyright and license notice
are preserved in any copy.
