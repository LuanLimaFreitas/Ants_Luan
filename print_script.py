import matplotlib.pyplot as plt
import math

gaming_info = open("gaming_info.txt", "r")
data = gaming_info.readlines()
current_line = 0

plt.figure(figsize=(13,8))
x_1 = float(data[current_line])
current_line += 1
x_2 = float(data[current_line])
current_line += 1
y_1 = float(data[current_line])
current_line += 1
y_2 = float(data[current_line])
current_line += 1
plt.ylim(y_1,y_2)
plt.xlim(x_1,x_2)


number_of_ants = int(data[current_line])
current_line += 1
ants_pos_x_list = []
ants_pos_y_list = []
for i in range(number_of_ants):
    ants_pos_x_list.append(float(data[current_line]))
    current_line += 1
    ants_pos_y_list.append(float(data[current_line]))
    current_line += 1
plt.plot(ants_pos_x_list,ants_pos_y_list,'X', label = "Initial distribuition of ants" )

initial_number_of_droplets = int(data[current_line])
current_line += 1
droplets_pos_x_list = []
droplets_pos_y_list = []
for i in range(initial_number_of_droplets):
    droplets_pos_x_list.append(float(data[current_line]))
    current_line += 1
    droplets_pos_y_list.append(float(data[current_line]))
    current_line += 1
plt.plot(droplets_pos_x_list,droplets_pos_y_list,'.', label = "Initial distribuition of pheromone droplets")

number_of_iterations = int(data[current_line])
current_line += 1
ant_0_pos_x_list = []
ant_0_pos_y_list = []
for i in range(number_of_iterations):
    ant_0_pos_x_list.append(float(data[current_line]))
    current_line += 1
    ant_0_pos_y_list.append(float(data[current_line]))
    current_line += 1
plt.plot(ant_0_pos_x_list,ant_0_pos_y_list, '.', label = "Trajectory of Ant 0")


plt.legend(fontsize = 14)
plt.show()

print(ants_pos_x_list[0],ants_pos_y_list[0])
