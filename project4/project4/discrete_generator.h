#ifndef DISCRETE_GENERATOR_H
#define DISCRETE_GENERATOR_H

/*
 This class generates a discrete distribution of numbers.
*/

class DiscreteGenerator
{
 int size;
 double* cdf;
 public:
    DiscreteGenerator(int, double*);
  //void init( int size_, double* probs );
  //Pre: SIZE_>0 and probabilities is size size.
  //Post: The generator is initialized
  
  int generateDist();
  //Pre: Initialized. SIZE isn't too large.
  //Post: A random number of the distribution is generated

  ~DiscreteGenerator();
  //Pre: SIZE_>0 and probabilities is size size.
  //Post: The generator is initialized
  
};

#endif
