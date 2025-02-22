#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

// Function to read integers from the file
std::vector<int> getValues(const std::string &filename)
{
  std::vector<int> values;
  std::ifstream file(filename); // Open the file

  if (!file) // Check if the file opened successfully
  {
    std::cerr << "Error opening file: " << filename << std::endl;
    return values; // Return empty vector
  }

  std::string line;
  while (std::getline(file, line)) // Read one line at a time
  {
    std::istringstream iss(line);
    int num;
    while (iss >> num) // Extract integers from the line
    {
      values.push_back(num);
    }
  }

  return values;
}

// Sort the array either in ascending or descending order
void sortArray(std::vector<int> &values, char &order)
{
  order == 'a' ? std::sort(values.begin(), values.end()) : std::sort(values.begin(), values.end(), std::greater<int>());
}

// Function to write sorted values to a new file
void writeValuesToFile(const std::vector<int> &values, const std::string &outputFilename)
{
  std::ofstream outputFile(outputFilename); // Open the output file

  if (!outputFile)
  {
    std::cerr << "Error opening output file: " << outputFilename << std::endl;
    return;
  }

  for (int value : values)
  {
    outputFile << value << '\n'; // Write each value to the file
  }

  std::cout << "Sorted values written to " << outputFilename << std::endl;
}

// find mean

// find median

// find mode

int main(int argc, char **argv)
{
  // Ensure a file is provided as an argument
  if (argc != 3 && argc != 4)
  {
    std::cerr << "Usage: " << argv[0] << "-a(ascending) or -d(descending) <input filename> <output filename>(optional)" << std::endl;
    return 1;
  }

  // get the desired order
  char order{argv[1][1]};
  if (argv[1][0] != '-' && (argv[1][1] != 'a' && argv[1][1] != 'd') && argv[1][2] != '\0')
  {
    std::cerr << "Must provide -a or -d specifier" << '\n';
    return 1;
  }

  // Read values from file
  std::vector<int> values = getValues(argv[2]);

  // sort the array
  sortArray(values, order);

  // Default output file name
  std::string outputFile{"sorted.txt"};
  if (argv[3])
  {
    outputFile = argv[3];
  }

  // print the values back to new file(sorted.txt)
  writeValuesToFile(values, outputFile);

  // ask user what else they would like

  // print median, mean, mode to file

  return 0;
}
