#ifndef __LOADMATRIX_H
#define __LOADMATRIX_H

#include <Eigen/Core>
#include <fstream>
#include <iostream>


namespace Eigen{

MatrixXd loadMatrix(const char* filename,int headerLines=0){

  std::vector<double> rawData;

  std::ifstream infile(filename);
  double d;
  for (int i=0;i<headerLines;i++){
    std::string line;
    getline(infile, line);
  }
  int cols=0,rows=0;
  while (! infile.eof()){
    std::string line;
      getline(infile, line);
      
      int temp_cols = 0;
      std::stringstream stream(line);
      while(! stream.eof()){
	stream>>d;
	rawData.push_back(d);
	temp_cols++;
      }      
	
      if (temp_cols == 0)
	continue;

      if (cols == 0)
	cols = temp_cols;

      rows++;
  }
  infile.close();


  rows--;

  // Populate matrix with numbers.
  MatrixXd result(rows,cols);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      result(i,j) = rawData[ cols*i+j ];
  
  return result;
}
  


void printSummary (const Ref<const MatrixXd> & m){
  int r=m.rows();
  int c=m.cols();
  std::cout<<"loaded "<<r<<"x"<<c<<" matrix. First row"<<std::endl<<m.row(0)<<std::endl<<"Last row"<<m.row(r-1)<<std::endl;
}

}


#endif
