#include "parameters.h"

float delta_t = .5f;

int number_of_ants = 1;
int initial_number_of_droplets = 200;

int number_of_iterations = 1000;

float const drop_every_iter = 50.;

float const droplet_too_old = 1000.;

float sensing_area_radius = 20.;

float const Pi =  3.1415926535;

float sensing_area_half_angle = 0.22*Pi;

float const Diffusion = 20.;
float const Evaporation = .0001;
float const Amount = 500.;

float const ignore_droplet_if_this_far = 5.*sensing_area_radius;
float const ignore_droplet_if_this_far2 = ignore_droplet_if_this_far*ignore_droplet_if_this_far;

float const x_1 = 0.;
float const x_2 = 1800.;
float const y_1 = 0.;
float const y_2 = 1500.;
float Lx = x_2-x_1;
float Ly = y_2-y_1;
std::vector<float> N = {Lx, 0.};
std::vector<float> S = {-Lx, 0.};
std::vector<float> W = {0., Ly};
std::vector<float> E = {0., -Ly};
std::vector<float> NW = {Lx, Ly};
std::vector<float> NE = {Lx, -Ly};
std::vector<float> SW = {-Lx, Ly};
std::vector<float> SE = {-Lx, -Ly};
std::vector<std::vector<float>> neighbor_squares = {N,S,W,E,NW,NE,SW,SE};

float zoom_multiplier = 1.;

int const seed1 = 999;

float const tau = .10;

float const threshold = 0.0001; // Too small?

std::string const BoundaryMethod = "periodic";      // "periodic" or "reflective"
