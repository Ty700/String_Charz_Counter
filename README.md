# String Charz Counter

A C++ command-line tool that analyzes text files and produces a characterization report for each one.

## What It Does

For every `.txt` file in the `test_files/` directory, String Charz Counter runs a suite of text analysis operations and writes the results to a corresponding `_charz.txt` file in the `output/` directory.

### Analysis Operations

| Metric | Description |
|---|---|
| Total Words | Count of whitespace-delimited words |
| Total Lines | Number of lines in the file |
| Total Spaces | Count of space characters |
| Longest Word(s) | The longest word(s); reports ties |
| Total Vowels | Count of vowel characters (a, e, i, o, u) |
| Total Consonants | Count of consonant characters |
| Total Characters | Total character count including whitespace |

### Example

Input (`test_files/test_file.txt`):
```
The cow jumped over the moon!
```

Output (`output/test_file_charz.txt`):
```
Total Words: 6
Total Lines: 1
Total Spaces: 5
Longest Word(s): jumped
Total Vowels: 9
Total Consonants: 14
Total Characters: 30
```

## How To: Add more analysis Operations

To add more analysis operations, follow these steps:

1. **Define the Operation**: Decide on the new metric you want to calculate (e.g., "Average Word Length").

2. **Implement the Logic**: Add a new function in `string_charz.cpp` that performs the calculation for the new metric. For example:
    ```cpp
    double calculateAverageWordLength(const std::string& str, std::ostream& outFile)) {
        size_t totalLength = 0;

        /* Assuming splitIntoWords is a helper function that splits the input string into words */
        std::vector<std::string> words = splitIntoWords(str); 

        for (const auto& word : words) {
            totalLength += word.length();
        }

        double averageLength = words.empty() ? 0 : static_cast<double>(totalLength) / words.size();

        outFile << "Average Word Length: " << averageLength << std::endl;
    }
    ```

3. **Add operation to operations vector** in 'string_charz.cpp' file: Add a new entry to the `operations` vector in the `analyzeFile` function to include your new operation. For example:
    ```cpp
    operations.push_back([this](const std::string& s, std::ostream& o){ calculateAverageWordLength(s, o); });
    ```

4. **Add Operation Function Declaration in `string_charz.hpp`**: Declare the new function in the header file so it can be used in the main analysis flow.
    ```cpp
    /* existing declarations */ 
    ...
    double calculateAverageWordLength(const std::string& str, std::ostream& outFile);
    ...
    /* Rest of the declarations */
    ```

5. **Rebuild the Project**: Run the build script to compile the changes and test the new operation.

## Project Structure

```
String_Charz_Counter/
├── src/
│   ├── main.cpp           # Entry point; scans test_files/ and runs StringCharz
│   └── string_charz.cpp   # StringCharz implementation
├── lib/
│   ├── string_charz.hpp   # StringCharz class declaration
│   └── util.hpp           # LOG macro for debug builds
├── test_files/            # Input .txt files to analyze
├── output/                # Generated _charz.txt report files
├── bin/                   # Compiled binaries (release/ and debug/)
├── build/                 # CMake build directory
├── CMakeLists.txt
└── build.py               # Build & run script
```

## Building

Requires CMake 3.28+ and a C++17-compatible compiler.

```bash
# Production build + run
python3 build.py

# Debug build + run (enables LOG() output)
python3 build.py -d

# Clean build artifacts
python3 build.py -c

# Help
python3 build.py -h
```

Binaries are placed in `bin/release/` or `bin/debug/`.

## Running

After building, the binary can be run directly:

```bash
./bin/release/String_Charz_Counter
```

The program reads all files from `./test_files/` and writes reports to `./output/`.
