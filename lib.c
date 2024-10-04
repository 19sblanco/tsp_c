#include <math.h>
#include <time.h>
#include <float.h>

typedef struct
{
    double x;
    double y;
} city;

city make_city(double x, double y)
{
    city c;
    c.x = x;
    c.y = y;
    return c;
}

void print_cities(city *cities, int *order, int n)
{
    for (int i = 0; i < n; i++)
    {
        city c = cities[order[i] - 1];
        if (i == (n - 1))
        {
            printf("(%f, %f)", c.x, c.y);
        }
        else
        {
            printf("(%f, %f) -> ", c.x, c.y);
        }
    }
}

void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

double get_distance(city c1, city c2)
{
    return pow(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2), .5);
}

void get_distances(double *distances, city *cities, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double dist = get_distance(cities[i], cities[j]);
            distances[(i * n) + j] = dist;
        }
    }
}

void print_distances(double *distances, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%f ", distances[(i * n) + j]);
        }
        printf("\n\n");
    }
}

/*
remove an item from an array where n is the size of original
*/
void _remove(int *original, int *new, int item, int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (original[i] == item)
        {
            continue;
        }
        else
        {
            new[j] = original[i];
            j++;
        }
    }
}

/*
add an item to an array where n is the size of original
*/
void _add(int *original, int *new, int item, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        new[i] = original[i];
    }
    new[i] = item;
}

/*
copy an array of size n
*/
void _copy(int *original, int *new, int n)
{
    for (int i = 0; i < n; i++)
    {
        new[i] = original[i];
    }
}

/*
given an array make its elements 0-(n-1)
*/
void _range(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
}

/*
set available cities where each bit represents if a city
has been visited or not. A bit of:
    1 represents a city being available to visit
    0 represents a city not being avaiable to visit

*/
unsigned int set_available_cities(unsigned int n) {
    int ret = 0;
    for (int i = 1; i < n; i++) {
        ret |= (1 << i);
    }
    return ret;
}

void printBinary(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf(" (%u)\n", num);
}

// global variables for the tsp and tsp_helper functions below
double best_so_far;
int fc = 0; // first city will always have an id of 0
double* distances; // distance matrix for each city
int n; // number of cities

/*
The recursive tsp function
This uses a method called backtracking,
*/
unsigned int tsp_helper(unsigned int cc, unsigned int ac) 
{
    // if (curr_distance > best_so_far) {
    //     *rdistance = curr_distance;
    //     return;
    // }

    // int ac_len = n - (depth + 1);
    // if (ac_len == 0)
    // {
    //     *rdistance = curr_distance + distances[(cc * n) + fc];
    //     if (*rdistance < best_so_far) {
    //         best_so_far = *rdistance;
    //     }
    //     _copy(curr_path, rpath, n);
    //     return;
    // }

    // double s_d_sofar = -1.0;
    // int s_p_sofar[n];

    // for (int i = 0; i < n; i++)
    // {
    //     // int ac = avail_cities[i];
    //     if (!((avail_cities >> i) & 1)) {
    //         continue;
    //     }
    //     double new_dist = curr_distance + distances[(cc * n) + ac];
    //     int new_ac[ac_len - 1];
    //     _remove(avail_cities, new_ac, ac, ac_len);
    //     int new_path[depth + 1];
    //     _add(curr_path, new_path, ac, depth);
    //     double best_distance;
    //     int best_path[n];
    //     tsp_helper(&best_distance, best_path, new_dist, new_path, ac, new_ac, depth + 1);
    //     if ((s_d_sofar == -1.0) || (best_distance < s_d_sofar))
    //     {
    //         s_d_sofar = best_distance;
    //         _copy(best_path, s_p_sofar, n);
    //     }
    // }
    // *rdistance = s_d_sofar;
    // _copy(s_p_sofar, rpath, n);
}

/*
given n city coordinates
return the shortest path and the distance of that path
*/
void tsp(double *rdistance, int *rpath, city *cities, int num_cities)
{
    // set globals
    best_so_far = DBL_MAX;
    n = num_cities;
    double d[n * n];
    distances = d;
    get_distances(distances, cities, n);

    unsigned int available_cities = set_available_cities(n);
    unsigned int current_city = 0;
    unsigned int distance = tsp_helper(current_city, available_cities);

    // tsp_helper(distance, path, 0, path_so_far, 0, available_cities, 0);
}

/*
check whether or not a city is withing the threshold distance of
the other cities
*/
int within_range(city *cities, int n, city c, double threshold)
{
    for (int i = 0; i < n; i++)
    {
        double dist = get_distance(c, cities[i]);
        if (dist < threshold)
        {
            return 1;
        }
    }
    return 0;
}

/*
creates random cities and stores them in the cities array
if the cities are withing a certain distance of one another,
create another random city and try again
*/
void random_cities(city *cities, int n, double threshold)
{
    srand(time(NULL));
    int x, y, in_range;
    city c;
    for (int i = 0; i < n; i++)
    {
        while (1)
        {
            x = rand();
            y = rand();
            c = make_city(x, y);
            in_range = within_range(cities, i, c, threshold);
            if (in_range == 0)
            {
                break;
            }
        }
        cities[i] = c;
    }
}

/*
receive the number of cities that the user wants
*/
int input_random_cities()
{
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);
    return number;
}
