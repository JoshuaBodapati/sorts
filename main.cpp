#include "bubbleSort.h"
#include "utility.h"
#include <random>
#include <string>

/* TODOS
add the possibility of sorted and nearly sorted (make switch case)
implement the following(lowercase means done):
  bubble
  SELECTION
  INSERTION
  MERGE
  QUICK
  RANDOM_QUICK
  COUNT
  RADIX_SORT
*/

static const bool boost = []() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    return std::ios_base::sync_with_stdio(false);
}();

struct Options {
  bool bubble = false;
  bool selection = false;
  bool insertion = false;
  bool merge = false;
  bool quick = false;
  bool random_quick = false;
  bool count = false;
  bool radix_sort = false;
};  // Options{}

void printHelp(char *argv[]);

void getOptions(int argc, char *argv[], Options &options);

int main(int argc, char *argv[]) {
  Options options;
  getOptions(argc, argv, options);

  // Define the size of the vector and the range of random numbers
  const int vector_size = 10;
  const int min_value = 1;
  const int max_value = 100;

  // Create a random device and a random number generator
    std::random_device rd;  // Non-deterministic random number generator
    std::mt19937 gen(rd()); // Mersenne Twister engine seeded with rd()
    std::uniform_int_distribution<> dis(min_value, max_value); // Uniform distribution

    // Create the vector and fill it with random numbers
    std::vector<int> random_vector(vector_size);
    for (int& value : random_vector) {
        value = dis(gen); // Generate a random number for each element
    }
    // Output the generated random vector
    std::cout << "Before sort:\n";
    cout << "{";
    for (size_t i = 0; i < random_vector.size()-1; i++) {
        std::cout << random_vector[i] << ", ";
    }
    
    cout << random_vector[random_vector.size()-1] << "}\n";

    if(options.bubble) {
      Bubble bubble(random_vector);
      bubble.bubbleSort();
      bubble.outputResults();
    }

}

// Parse command-line arguments
void getOptions(int argc, char *argv[], Options &options) {
  opterr = 0;  // Disable getopt's own error messages
  int choice;
    // Define long and short options
  option long_options[] = {
    {"bubble", no_argument, nullptr, 'b'},
    {"selection", no_argument, nullptr, 's'},
    {"insertion", no_argument, nullptr, 'i'},
    {"merge", no_argument, nullptr, 'm'},
    {"random_quick", no_argument, nullptr, 'r'},
    {"count", no_argument, nullptr, 'c'},
    {"radix", no_argument, nullptr, 'x'},
    {"help", no_argument, nullptr, 'h'},
    {nullptr, 0, nullptr, '\0'}
  };

  while ((choice = getopt_long(argc, argv, "bsimrcxh", long_options, nullptr)) != -1) {
    switch (choice) {
      case 'b':
        options.bubble = true;
        break;
      case 's':
        options.selection = true;
        break;
      case 'i':
        options.insertion = true;
        break;
      case 'm':
        options.merge = true;
        break;
      case 'r':
        options.random_quick = true;
        break;
      case 'c':
        options.count = true;
        break;
      case 'x':
        options.radix_sort = true;
        break;
      case 'h':
        printHelp(argv);
        exit(0);
      default:
        cerr << "Unknown command line option\n";
        exit(1);
    }
  }
}  // getOptions()


// Print help message for the user
void printHelp(char *argv[]) {
  cout << "Usage: " << argv[0] << " [options]\n";
  cout << "Options:\n";
  cout << "-h, --help            Outputs this help message\n"; 
  cout << "-b, --bubble          Enable bubble sort\n";
  cout << "-s, --selection       Enable quick sort\n";
  cout << "-i, --insertion       Enable insertion sort\n";
  cout << "-m, --merge           Enable merge sort\n";
  cout << "-q, --quick           Enable quick sort\n";
  cout << "-r, --random_quick    Enable random-quick sort\n";
  cout << "-c, --count           Enable count sort\n";
  cout << "-x, --radix           Enable radix sort\n";
}// printHelp()