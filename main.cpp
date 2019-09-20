#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>
#include <fstream>
using namespace std;

#include "auxiliary_functions.h"
#include "parameters.h"

#include "network.h"
#include "droplet.h"
#include "ant.h"

float game(Network Net);
///  Aqui fica a musculatura do programa. Uma chamada da função 'game'
///  simula um período determinado de vida de uma colônia de formigas
///  cuja lei de movimento é definida mediante a rede neural 'Net'.
///  Seu retorno é a pontuação da colônia, definida como a quantidade
///  total de feromônio percebido pelas formigas. Tal resultado deve ser
///  interpretado do ponto de vista total da evolução dos sistemas neurais
///  como a pontuação da rede neural.


int main()
{
    cout << "Hello World!" << endl;

    std::vector<int> s = {2,3,2};
    std::vector<std::vector<std::vector<float>>> w = {  { {1,0,0},{0,1,0} } , {{1,0},{0,1},{0,0}}  };
    std::vector<std::vector<float>> b = {  {0,0,0} , {0,0}  };
    Network net(s,w,b);
    std::size_t i = 0;
    while( i<1 )
    {
        cout << game(net) << endl;
        i++;
    }
    cout << "over" << endl;
    return 0;
}

float game(Network Net)
{
    ofstream gaming_info;
    gaming_info.open( "gaming_info.txt", ios::out | ios::trunc );
    gaming_info << x_1 << endl;
    gaming_info << x_2 << endl;
    gaming_info << y_1 << endl;
    gaming_info << y_2 << endl;
    float score = 0;
    int i;

    /// Step 1.1: Initialize the ants at random positions. Question: Should
    /// we initialize them all at the same time or, instead, progressively?
    ///
    std::vector<Ant*> all_ants;
    gaming_info << number_of_ants << endl;
    for ( i = 0; i<number_of_ants; i++)
    {
        all_ants.push_back(new Ant());
        all_ants[i]->load_at(333,999,Net); // Currently NOT initializing the ants randomly.
        gaming_info << all_ants[i]->pos_x << endl;
        gaming_info << all_ants[i]->pos_y << endl;
    }

    /// Step 1.2: Initialize the pheromone landscape.
    ///
    std::vector<Droplet> all_droplets = {};
    int last_drop_iter = -999;  // '-999' is just a small enough number.
    gaming_info << initial_number_of_droplets << endl;
    std::vector<std::vector<float>> trail = straight_trail(0.);
    for (  i = 0; i<initial_number_of_droplets; i++)
    {
        float droplet_center_x = trail[0][i];
        float droplet_center_y = trail[1][i];
        float droplet_origin_time = trail[2][i];
        if( droplet_origin_time > last_drop_iter)  // We wish to record the greatest 'droplet_origin_time'.
            last_drop_iter = droplet_origin_time;
        gaming_info << droplet_center_x << endl;
        gaming_info << droplet_center_y << endl;
        all_droplets.push_back(Droplet(droplet_origin_time,droplet_center_x,droplet_center_y));
    }

    Droplet::number_of_droplets = initial_number_of_droplets;

    /// Step 2: Several cicles of ant updating, pheromone droping and
    /// pheromone erasing.
    ///
    float Time = 0;
    std::size_t j;
    gaming_info << number_of_iterations << endl;
    while( Time < number_of_iterations )
    {

        /// Step 2.1: Check if it's time to leave some droplets
        /// - Probably a good time to erase some droplets too!
        ///
        if( Time - last_drop_iter >= drop_every_iter)
        {
            last_drop_iter = Time;
            for( j=0 ; j < all_ants.size(); j++ )
                all_droplets.push_back(Droplet(Time,all_ants[j]->pos_x,all_ants[j]->pos_y));
            /// Now checking for outdated droplets.
            for( j=0; j < all_droplets.size(); j++ ) // Improve this!
            {
                if (exp(-Evaporation * all_droplets[j].elapsed_time(Time)) * Amount <= .01)
                {
                    all_droplets.erase(all_droplets.begin()+j);
                    Droplet::number_of_droplets--;
                }
            }
        }
        else
        {    /// Step 2.2: Update our little anties and record the pheromone they feel. The ants
             /// will either drop pheromone or walk. This is meant to avoid undetermined results
             /// in the heat equation when 'elapsed time' = 0. Still, it appears to be a reasonable
             /// and natural behavior.
            for( j=0; j<all_ants.size(); j++ )
            {
                float some_points = all_ants[j]->update(Time,all_droplets); // Sounds easy, eh?
                score += some_points;
            }
        }

        gaming_info << all_ants[0]->pos_x << endl;
        gaming_info << all_ants[0]->pos_y << endl;

        Time++;
    }

//           /// Step 3: Now pass some additional information to the 'gaming_info'
//           /// file.
//           ///
//           gaming_info << all_droplets.size() << endl;
//           for( i = 0; i < all_droplets.size(); i++)
//           {
//               gaming_info << all_droplets[i].pos_x << endl;
//               gaming_info << all_droplets[i].pos_y << endl;
//           }

    gaming_info.close();
    return score;
}
