#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  if (argc != 3) {
    cerr << "Error usage: " << argv[0] << " <input file> <output file>" << endl;
    exit(1);
  }

  ifstream in(argv[1]);
  if (in.fail()) {
    cerr << "Error opening input file " << argv[1] << endl;
    exit(2);
  }
  ofstream out(argv[2]);
  if (out.fail()) {
    cerr << "Error opening output file" << argv[2] << endl;
    in.close();
    exit(3);
  }
  char *buffer = new char[256];
  while (in.getline(buffer, 256)) {
    out << buffer << endl;
  }

  in.close();
  out.close();
  return 0;
}
