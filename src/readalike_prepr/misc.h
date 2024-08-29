#include <fstream>
#include <string>

#define COMP_INTRO_END_LINE 29
#define COMP_MAIN_END_LINE  13146932
#define COMP_CODA_END_LINE  13147025

#define DECOMP_MAIN_END_LINE  12354827
#define DECOMP_INTRO_END_LINE 12354856
#define DECOMP_CODA_END_LINE  12354951

void split4Comp(char const *enwik9_filename) {
  std::ifstream ifile(enwik9_filename); 
  std::ofstream ofile1(".intro"); 
  std::ofstream ofile2(".main"); 
  std::ofstream ofile3(".coda"); 

  int line_count = 0;

  std::string s;
  while (std::getline(ifile, s)) {
    if (line_count < COMP_INTRO_END_LINE) {
      ofile1 << s << std::endl;
    } else if (line_count < COMP_MAIN_END_LINE) {
        ofile2 << s << std::endl;
      } else if (line_count < COMP_CODA_END_LINE) {
          ofile3 << s << std::endl;
          } else {
            ofile3 << s; 
          }
    line_count++;
  }

  ofile1.close();
  ofile2.close();
  ofile3.close();
}

void split4Decomp() {
  std::ifstream ifile(".input_decomp"); 
  std::ofstream ofile1(".intro_decomp"); 
  std::ofstream ofile2(".main_decomp"); 
  std::ofstream ofile3(".coda_decomp"); 

  int line_count = 0;

  std::string s;
  while (std::getline(ifile, s)) {
    if (line_count < DECOMP_MAIN_END_LINE) {
      ofile2 << s << std::endl;
      if(line_count == DECOMP_MAIN_END_LINE - 1)
        std::cout << s << std::endl << std::flush;
    } else if (line_count < DECOMP_INTRO_END_LINE) {
        ofile1 << s << std::endl;
        if(line_count == DECOMP_INTRO_END_LINE - 1)
          std::cout << s << std::endl << std::flush;
      } else if (line_count < DECOMP_CODA_END_LINE) {
          ofile3 << s << std::endl;
          if(line_count == DECOMP_CODA_END_LINE - 1)
            std::cout << s << std::endl << std::flush;
          } else {
            ofile3 << s; 
          }
    line_count++;
  }

  ofile1.close();
  ofile2.close();
  ofile3.close();
}
