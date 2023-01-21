#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRIPS 100

typedef struct {
  char departure[50];
  char destination[50];
  int price;
  char description[500];
} Trip;

Trip trips[MAX_TRIPS];
int numTrips = 0;

void addTrip() {
  if (numTrips == MAX_TRIPS) {
    printf("Error: no more room for new trips.\n");
    return;
  }

  Trip trip;
  printf("Enter trip departure: ");
  scanf("%s", trip.departure);
  printf("Enter trip destination: ");
  scanf("%s", trip.destination);
  printf("Enter trip price: ");
  scanf("%d", &trip.price);
  printf("Enter trip description: ");
  scanf("%s", trip.description);

  trips[numTrips++] = trip;
}

void modifyTrip() {
  int tripIndex;
  printf("Enter the index of the trip you want to modify: ");
  scanf("%d", &tripIndex);

  if (tripIndex < 0 || tripIndex >= numTrips) {
    printf("Error: invalid trip index.\n");
    return;
  }

  Trip trip = trips[tripIndex];
  printf("Enter new trip departure (%s): ", trip.departure);
  scanf("%s", trip.departure);
  printf("Enter new trip destination (%s): ", trip.destination);
  scanf("%s", trip.destination);
  printf("Enter new trip price (%d): ", trip.price);
  scanf("%d", &trip.price);
  printf("Enter new trip description (%s): ", trip.description);
  scanf("%s", trip.description);

  trips[tripIndex] = trip;
}

void deleteTrip() {
  int tripIndex;
  printf("Enter the index of the trip you want to delete: ");
  scanf("%d", &tripIndex);

  if (tripIndex < 0 || tripIndex >= numTrips) {
    printf("Error: invalid trip index.\n");
    return;
  }

  // Shift the following trips one position to the left to fill the gap.
  for (int i = tripIndex; i < numTrips - 1; i++) {
    trips[i] = trips[i + 1];
  }

  numTrips--;
}
void searchTripsByDate() {
  char startDate[50];
  char endDate[50];
  printf("Enter start date: ");
  scanf("%s", startDate);
  printf("Enter end date: ");
  scanf("%s", endDate);

  printf("Trips found:\n");
  for (int i = 0; i < numTrips; i++) {
    Trip trip = trips[i];
    if (strcmp(trip.departure, startDate) >= 0 && strcmp(trip.departure, endDate) <= 0) {
      printf("%d. %s - %s (%d)\n", i, trip.departure, trip.destination, trip.price);
    }
  }
}
void searchTripsByPrice() {
  int minPrice;
  int maxPrice;
  printf("Enter minimum price: ");
  scanf("%d", &minPrice);
  printf("Enter maximum price: ");
  scanf("%d", &maxPrice);

  printf("Trips found:\n");
  for (int i = 0; i < numTrips; i++) {
    Trip trip = trips[i];
    if (trip.price >= minPrice && trip.price <= maxPrice) {
      printf("%d. %s - %s (%d)\n", i, trip.departure, trip.destination, trip.price);
    }
  }
}

void searchTripsByCities() {
  char departure[50];
  char destination[50];
  printf("Enter departure city: ");
  scanf("%s", departure);
  printf("Enter destination city: ");
  scanf("%s", destination);

  printf("Trips found:\n");
  for (int i = 0; i < numTrips; i++) {
    Trip trip = trips[i];
    if (strcmp(trip.departure, departure) == 0 && strcmp(trip.destination, destination) == 0) {
      printf("%d. %s - %s (%d)\n", i, trip.departure, trip.destination, trip.price);
    }
  }
}

void displayAllTrips() {
  for (int i = 0; i < numTrips; i++) {
    Trip trip = trips[i];
    printf("%d. %s - %s (%d)\n", i, trip.departure, trip.destination, trip.price);
  }
}

void displayTripDescription() {
  int tripIndex;
  printf("Enter the index of the trip you want to display the description for: ");
  scanf("%d", &tripIndex);

  if (tripIndex < 0 || tripIndex >= numTrips) {
    printf("Error: invalid trip index.\n");
    return;
  }

  Trip trip = trips[tripIndex];
  printf("%s\n", trip.description);
}
int main() {
  int choice;
  while (1) {
    printf("\n************* TRAVEL MANAGER APP ************** \n");
    printf("1. Add a trip\n");
    printf("2. Modify a trip\n");
    printf("3. Delete a trip\n");
    printf("4. Search trips by date\n");
    printf("5. Search trips by price\n");
    printf("6. Search trips by cities\n");
    printf("7. Display all trips\n");
    printf("8. Display trip description\n");
    printf("9. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addTrip();
        break;
      case 2:
        modifyTrip();
        break;
      case 3:
        deleteTrip();
        break;
      case 4:
        searchTripsByDate();
        break;
      case 5:
        searchTripsByPrice();
        break;
      case 6:
        searchTripsByCities();
        break;
      case 7:
        displayAllTrips();
        break;
      case 8:
        displayTripDescription();
        break;
      case 9:
        return 0;
      default:
        printf("Error: invalid choice.\n");
        break;
    }
  }
}
