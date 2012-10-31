/*
 This class generates a discrete distribution of numbers based,
on the Smirnov transform method.
*/

#include "discrete_generator.h"
#include <random>


  void DiscreteGenerator::init( int size_, double* probs)
  //Pre: SIZE_>0 and probabilities is size SIZE_.
  //Post: The generator is initialized
  {
   size = size_;
   cdf = new double[size];
   cdf[0] = probs[0];
   for(int i=1;i<size;i++){
    cdf[i]=cdf[i-1]+probs[i];
   }
   cdf[size-1]=1.0;
  }
  
  int DiscreteGenerator::generate()
  //Pre: Initialized. SIZE isn't too large.
  //Post: A random number of the distribution is generated
  {
   double number = (std::rand()%10000000)/10000000.0;
   int i=-1;
   while(number>=cdf[++i]);
   return i;
  }

  DiscreteGenerator::~DiscreteGenerator( )
  {
   delete[] cdf;
  }
