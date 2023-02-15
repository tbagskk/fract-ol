#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

int main() {
  // Définition des constantes et des variables
  const int width = 640;
  const int height = 480;
  const int max_iterations = 256;
  const double xmin = -2.0;
  const double xmax = 1.0;
  const double ymin = -1.5;
  const double ymax = 1.5;
  const double xstep = (xmax - xmin) / (double)width;
  const double ystep = (ymax - ymin) / (double)height;

  int x, y, i;
  double creal, cimag;
  double real, imag;
  double complex z, c;
  double modulus;

  // Parcourir chaque pixel de l'image
  for (y = 0; y < height; y++) {
    for (x = 0; x < width; x++) {
      // Calculer les coordonnées complexes correspondantes
      creal = xmin + (double)x * xstep;
      cimag = ymax - (double)y * ystep;

      // Initialiser z et c à la valeur de départ
      z = 0.0 + 0.0 * I;
      c = creal + cimag * I;

      // Effectuer la boucle de calcul de Mandelbrot
      for (i = 0; i < max_iterations; i++) {
        z = z * z + c;
        modulus = cabs(z);
        if (modulus > 2.0) {
          // Le point ne fait pas partie de la fractale
          break;
        }
      }

      // Déterminer la couleur du pixel en fonction du nombre d'itérations
      if (i == max_iterations) {
        printf("0 0 0 "); // Noir pour les points dans la fractale
      } else {
        // Variation de couleur en fonction du nombre d'itérations
        double hue = (double)i / (double)max_iterations;
        hue = fmod(hue + 0.2, 1.0); // Fait varier la couleur
        printf("%d %d %d ", (int)(hue * 255), (int)(hue * 255), (int)(hue * 255));
      }
    }
    printf("\n");
  }

  return 0;
}
