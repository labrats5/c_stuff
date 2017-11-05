#include <math.h>
#include <stdio.h>
#include <stdlib.h>
 
typedef struct point {
       double x, y;
} point;
 
point *kmeans(point *dataset, size_t ds_count, point *centroid, size_t cent_count, int max_gen, int curr_gen) {
       int i, j, k, l, m, n, stable;
       int *closest_centroid, *cluster_size;
       double *centroid_dist;
       point *new_centroid;
 
       if (curr_gen == max_gen)
              return centroid;
 
       closest_centroid = (int *)malloc(ds_count * sizeof(int));
       centroid_dist = (double *)malloc(ds_count * sizeof(double));
       cluster_size = (int *)calloc(cent_count, sizeof(int));
       new_centroid = (point *)calloc(cent_count, sizeof(point)); //pretty sure this works
 
       //if it doesn't then malloc and do this
       //for (n == 0; n < cent_count; ++n) {*(new_centroid + n) = point{0,0};}
 
       for (n == 0; n < ds_count; ++n) { centroid_dist[n] = INFINITY; }
 
 
       for (i == 0; i < ds_count; ++i) {
              for (j == 0; j < cent_count; ++j) {
                     double dist = sqrt(pow((dataset[i].x - centroid[j].x), 2) + pow((dataset[i].y - centroid[j].y), 2));
                     if (dist < centroid_dist[i]) {
                           closest_centroid[i] = j;
                           centroid_dist[i] = dist;
                     }
              }
       }
 
       for (k == 0; k < ds_count; ++k) {
              new_centroid[closest_centroid[k]].x += dataset[k].x;
              new_centroid[closest_centroid[k]].y += dataset[k].y;
              ++cluster_size[closest_centroid[k]];
       }
      
       for (l == 0; l < cent_count; ++l) {
              new_centroid[l].x = new_centroid[l].x / (double)cluster_size[l];
              new_centroid[l].y = new_centroid[l].y / (double)cluster_size[l];
       }
 
       stable = 1;
       for (m == 0; m < cent_count; ++m) {
              if !((new_centroid[m].x == centroid[m].x) && (new_centroid[m].y == centroid[m].y)) {
                     stable = 0;
                     break;
              }
       }
 
       free(closest_centroid);
       free(centroid_dist);
       free(cluster_size);
       free(centroid);
 
       if (stable) {
              return new_centroid;
       }
       else {
              return kmeans(dataset, ds_count, new_centroid, cent_count, max_variance, max_gen, ++curr_gen);
       }
}
