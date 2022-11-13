import pygad
import pygad.nn
import pygad.gann
import numpy as np

input_data = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
output_data = np.array([0, 1, 1, 0])

num_inputs = len(input_data[0])
num_classes = 2 # 0 or 1
num_solutions = 10
last_fitness = 0

GANN_instance = pygad.gann.GANN(
    num_solutions=num_solutions,
    num_neurons_input=num_inputs,
    num_neurons_hidden_layers=[2],
    num_neurons_output=num_classes,
    hidden_activations=["sigmoid"],
    output_activation="softmax"
)

def fitness_func(soln, soln_idx):
    global GANN_instance, input_data, output_data

    predictions = pygad.nn.predict(
        last_layer=GANN_instance.population_networks[soln_idx],
        data_inputs=input_data
    )

    correct_preds = np.where(predictions == output_data)[0].size
    fitness_soln = (correct_preds / output_data.size) * 100

    return fitness_soln

def callback_each_gen(ga_instance):
    global GANN_instance, last_fitness

    population_matices = pygad.gann.population_as_matrices(
        population_networks=GANN_instance.population_networks,
        population_vectors=ga_instance.population
    )
    GANN_instance.update_population_trained_weights(population_trained_weights=population_matices)

    print(f"Gen: {ga_instance.generations_completed}")
    print(f"Fitness: {ga_instance.best_solution()[1]}")
    print(f"Change: {ga_instance.best_solution()[1] - last_fitness}\n")

    last_fitness = ga_instance.best_solution()[1].copy()

population_vectors = pygad.gann.population_as_vectors(
    population_networks=GANN_instance.population_networks
)

initial_population = population_vectors.copy()
num_of_parents_mating = 4
num_of_generations = 50
mutation_percent_genes = 20
parent_selection_type = "tournament"
crossover_type = "uniform"
mutation_type = "random"
keep_parents = 1
init_low_range = -3
init_high_range = 3

print("--- Starting Evolution ---\n")

ga_instance = pygad.GA(
    num_generations=num_of_generations,
    num_parents_mating=num_of_parents_mating,
    initial_population=initial_population,
    fitness_func=fitness_func,
    mutation_percent_genes=mutation_percent_genes,
    init_range_low=init_low_range,
    init_range_high=init_high_range,
    parent_selection_type=parent_selection_type,
    crossover_type=crossover_type,
    mutation_type=mutation_type,
    keep_parents=keep_parents,
    on_generation=callback_each_gen
)

ga_instance.run()
graph_choice = input("Plot graph [Y/n]: ")

if graph_choice in ['Y', 'y']:
    ga_instance.plot_fitness()
elif graph_choice in ['N', 'n']:
    pass
else:
    print("\nInvalid input, skipping..")

print("\n--- Best Generation Details ---\n")

soln, soln_fitness, soln_idx = ga_instance.best_solution()
print(f"Best solution's parameters:\n{soln}")
print(f"Best solution's fitness values: {soln_fitness}")
print(f"Best solution's index: {soln_idx}")

if ga_instance.best_solution_generation != -1:
    print(f"Best fitness value reached after {ga_instance.best_solution_generation} generations.")

preds = pygad.nn.predict(
    last_layer=GANN_instance.population_networks[soln_idx],
    data_inputs=input_data
)

print("\n--- Predictions Using Trained Network ---")

print(f"\nPredictions of the trained network using GA: {preds}")

wrong_instances = np.where(preds != output_data)[0].size
correct_instances = output_data.size - wrong_instances
accuracy = (correct_instances / output_data.size) * 100

print(f"Correctly classified instances: {correct_instances}")
print(f"Wrongly classified instances: {wrong_instances}")
print(f"Accuracy of the classification: {accuracy}")
