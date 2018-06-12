#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP


class Parameters {
public:
  Parameters(int n_cycles=10, int n_steps=10, int system_size_x=1000, int system_size_y=1000);
  virtual ~Parameters();

  int n_cycles;
  int n_steps;
  int system_size_x;
  int system_size_y;
};

#endif
