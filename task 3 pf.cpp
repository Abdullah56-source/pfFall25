#include <stdio.h>

#define ROWS 3
#define COLS 3


#define POWER        (1 << 0)   
#define OVERLOAD     (1 << 1)   
#define MAINTENANCE  (1 << 2)   
void update(int grid[ROWS][COLS], int r, int c, int flag, int set) {
    if (set)
        grid[r][c] |= flag;
    else
        grid[r][c] &= ~flag;
    printf("Sector [%d][%d] updated!\n", r, c);
}


void show(int grid[ROWS][COLS], int r, int c) {
    int s = grid[r][c];
    printf("\nSector [%d][%d] Status:\n", r, c);
    printf("Power: %s\n", (s & POWER) ? "ON" : "OFF");
    printf("Overload: %s\n", (s & OVERLOAD) ? "YES" : "NO");
    printf("Maintenance: %s\n", (s & MAINTENANCE) ? "YES" : "NO");
}


void diagnostic(int grid[ROWS][COLS]) {
    int overload = 0, maintenance = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] & OVERLOAD) overload++;
            if (grid[i][j] & MAINTENANCE) maintenance++;
        }
    }

    printf("\n=== SYSTEM REPORT ===\n");
    printf("Overloaded sectors: %d\n", overload);
    printf("Maintenance needed: %d\n", maintenance);
}


int main() {
    int grid[ROWS][COLS] = {0};
    int choice, r, c, flag, set;

    do {
        printf("\n--- IESCO GRID MENU ---\n");
        printf("1. Update Sector\n");
        printf("2. Show Sector Status\n");
        printf("3. Run Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter row and column: ");
                scanf("%d %d", &r, &c);

                printf("1.Power  2.Overload  3.Maintenance: ");
                scanf("%d", &flag);

                if (flag == 1) {
				
				
				flag = POWER;}
                else if (flag == 2) {
				flag = OVERLOAD;}
                else if (flag == 3){
				 flag = MAINTENANCE;}
                else {
                    printf("Invalid flag!\n");
                    break;
                }

                printf("Set (1) or Clear (0): ");
                scanf("%d", &set);
                update(grid, r, c, flag, set);
                break;

            case 2:
                printf("Enter row and column: ");
                scanf("%d %d", &r, &c);
                show(grid, r, c);
                break;

            case 3:
                diagnostic(grid);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}

