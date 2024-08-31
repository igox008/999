#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <limits.h>

#define MAX_FISH 100
#define MAX_DRONES 100
#define MAX_SCANS 100
#define MAX_RADAR_BLIPS 100

// bool check_path(int monster_x, int monster_y, int my_x, int my_y, int my_x_velo, int my_y_velo);
bool check_monster(int det[100][7], int i, int vis, int *monster_id, int x, int y, int light);
double dis(double drone_x, double drone_y, double cr_x, double cr_y);
bool if_scanned(int scansDroneById[100][100], int droneId, int fish_id);
int scan_count(int scans[100][100], int id);


void createVector(int x, int y, int vector[2]) {
    vector[0] = x;
    vector[1] = y;
}

// Function to create a new FishDetail
void createFishDetail(int color, int type, int fishDetail[2]) {
    fishDetail[0] = color;
    fishDetail[1] = type;
}

// Function to create a new Fish
void createFish(int i,int fishId, int pos[2], int speed[2], int detail[2], int fish[MAX_FISH][7]) {
    fish[i][0] = fishId;
    fish[i][1] = pos[0];
    fish[i][2] = pos[1];
    fish[i][3] = speed[0];
    fish[i][4] = speed[1];
    fish[i][5] = detail[0];
    fish[i][6] = detail[1];
    fish[i+1][0] = -42;
}

void scansDrone(int droneId, int fish_id, int drone[MAX_DRONES][MAX_SCANS])
{
    static int i;
    static int j;
    if (droneId == 0)
    {
        drone[droneId][i] = fish_id;
        i++;
        drone[droneId][i] = -42;
    }
    else
    {
        drone[droneId][j] = fish_id;
        j++;
        drone[droneId][j] = -42;
    }
}

// Function to create a new Drone
void createDrone(int droneId, int pos[2], int dead, int battery, int drone[MAX_DRONES][5]) {
    drone[droneId][0] = droneId;
    drone[droneId][1] = pos[0];
    drone[droneId][2] = pos[1];
    drone[droneId][3] = dead;
    drone[droneId][4] = battery;
}

// Function to create a new RadarBlip
void createRadarBlip(int fishId, char dir[], int radarBlip[MAX_RADAR_BLIPS][3]) {
    radarBlip[fishId][0] = fishId;
    radarBlip[fishId][1] = dir[0];
    radarBlip[fishId][2] = dir[1];
}

// void ft_normlize()
int main() {
    int fishCount;
    scanf("%d", &fishCount);

    int fishDetails[MAX_FISH][2];
    for (int i = 0; i < fishCount; i++) {
        int fishId, color, type;
        scanf("%d%d%d", &fishId, &color, &type);
        createFishDetail(color, type, fishDetails[fishId]);
    }

    // game loop
    while (1) {
        int myScans[MAX_SCANS];
        int foeScans[MAX_SCANS];
        int droneById[MAX_DRONES][5];
        int myDrones[MAX_DRONES][5];
        int scansDroneById[MAX_DRONES][MAX_SCANS];
        int foeDrones[MAX_DRONES][5];
        int visibleFishes[MAX_FISH][7];
        int visibleFishesById[MAX_FISH][7];
        int myRadarBlips[MAX_DRONES][MAX_RADAR_BLIPS][3];

        int myScore, foeScore;
        scanf("%d", &myScore);
        scanf("%d", &foeScore);

        int myScanCount;
        scanf("%d", &myScanCount);
        for (int i = 0; i < myScanCount; i++) {
            int fish_id;
            scanf("%d", &fish_id);
            myScans[i] = fish_id;
        }

        int foeScanCount;
        scanf("%d", &foeScanCount);
        for (int i = 0; i < foeScanCount; i++) {
            int fish_id;
            scanf("%d", &fish_id);
            foeScans[i] = fish_id;
        }

        int myDroneCount;
        scanf("%d", &myDroneCount);
        int d_id[2];
        for (int i = 0; i < myDroneCount; i++) {
            int droneId, droneX, droneY, dead, battery;
            scanf("%d%d%d%d%d", &droneId, &droneX, &droneY, &dead, &battery);
            int pos[2];
            pos[0] = droneX;
            pos[1] = droneY;
            createDrone(droneId, pos, dead, battery, myDrones);
            createDrone(droneId, pos, dead, battery, droneById);
            d_id[i] = droneId;
        }

        int foeDroneCount;
        scanf("%d", &foeDroneCount);
        for (int i = 0; i < foeDroneCount; i++) {
            int droneId, droneX, droneY, dead, battery;
            scanf("%d%d%d%d%d", &droneId, &droneX, &droneY, &dead, &battery);
            int pos[2];
            pos[0] = droneX;
            pos[1] = droneY;
            createDrone(droneId, pos, dead, battery,foeDrones);
            createDrone(droneId, pos, dead, battery,droneById);
        }

        int droneScanCount;
        scanf("%d", &droneScanCount);
        for (int i = 0; i < droneScanCount; i++) {
            int droneId, fish_id;
            scanf("%d %d", &droneId, &fish_id);
            scansDrone(droneId, fish_id, scansDroneById);
        }

        int visibleFishCount;
        scanf("%d", &visibleFishCount);
        int visible_monster_count = 0;
        for (int i = 0; i < visibleFishCount; i++) {
            int fishId, fishX, fishY, fishVx, fishVy;
            scanf("%d%d%d%d%d", &fishId, &fishX, &fishY, &fishVx, &fishVy);
            int pos[2], speed[2], detail[2];
            pos[0] = fishX;
            pos[1] = fishY;
            speed[0] = fishVx;
            speed[1] = fishVy;
            createFish(i, fishId,pos, speed, fishDetails[fishId], visibleFishes);
            createFish(fishId, fishId, pos, speed, fishDetails[fishId], visibleFishesById);
            if (fishId >= 16)
            {
                visible_monster_count++;
                fprintf(stderr,"id : %d\npos : {%d,%d}\n", fishId, fishX, fishY);
            }
        }

        int myRadarBlipCount;
        scanf("%d", &myRadarBlipCount);
        int monsters_count = 0;
        for (int i = 0; i < myRadarBlipCount; i++) {
            int droneId, fishId;
            char dir[3];
            scanf("%d%d%s", &droneId, &fishId, dir);
            createRadarBlip(fishId, dir, myRadarBlips[droneId]);
            int id;
            if (i == 0)
                id = droneId;
            if (id == droneId && fishId >= 16)
                monsters_count++;
        }
        static int iter;
        for (int i = 0; i < myDroneCount; i++) {
            int id = (i == 0 ? d_id[0] : d_id[1]);
            int x = myDrones[id][1];
            int y = myDrones[id][2];
            bool botom_check[8];
            bool run_after = false;
            int targetX[8];
            int targetY[8];
            char *status = "NaN";
            int light = 0;
            int monster_id;
            double tmp;
            static int x_check;

            int my_x_velo = 0;
            int my_y_velo = 0;
            // normal mode
            if ((iter % 3 == 0 || iter % 5 == 0) && y > 2500)
                light = 1;
            else
                light = 0;
            xc :
            if (x_check < 4 && x > 30)
                my_x_velo = -400;
            else if (x_check < 8)
                my_x_velo = 400;
            else
            {
                x_check = 0;
                goto xc;
            }
            x_check++;
            // my_x_velo = rand() % 401 - 200;

            targetX[id] = x + my_x_velo;
            if (y <= 30)
                botom_check[id] = false;
            else if (y >= 9900)
                botom_check[id] = true;
            if (!botom_check[id])
                my_y_velo = 800;
            else
                my_y_velo = -800;
            targetY[id] = y + my_y_velo;
            // fprintf(stderr, "target : {%d, %d}\n",x, y);
            if (visibleFishCount > 0 && !check_monster(visibleFishes, 0, visibleFishCount, &monster_id, x,y, light))
            {
                int cr_id;
                int i = 0;
                search :
                for (; i < visibleFishCount; i++)
                {
                    double d = dis((double)x,(double)y,(double)visibleFishes[i][1],(double)visibleFishes[i][2]);
                    //fprintf(stderr, "%lf %d %d (%d, %d)\n", d, visibleFishes[i][0], id,visibleFishes[i][1],visibleFishes[i][2]);
                    if (d < 2000)
                    {
                        run_after = true;
                        cr_id = visibleFishes[i][0];
                        break;
                    }
                }
                if (run_after && !if_scanned(scansDroneById,id,cr_id))
                {
                    targetX[id] = visibleFishesById[cr_id][1];
                    targetY[id] = visibleFishesById[cr_id][2];
                }
                else if (if_scanned(scansDroneById,id,cr_id) && i < visibleFishCount)
                {
                    i++;
                    goto search;
                }
            }
            else if (visibleFishCount > 0 && check_monster(visibleFishes, 0, visibleFishCount, &monster_id, x,y, light))
            {
                status = "RUN";
                static bool no_way;
                int monster_x = visibleFishesById[monster_id][1];
                int monster_y = visibleFishesById[monster_id][2];
                int pr_x = monster_x + visibleFishesById[monster_id][3];
                int pr_y = monster_y + visibleFishesById[monster_id][4];
                if (scan_count(scansDroneById, id) > 3)
                {
                    no_way = true;
                    targetY[id] = 0;
                }
                if (y <= 50)
                    no_way = false;
                if (dis(x,y, monster_x,monster_y) < 2000 && !no_way)
                {
                    if (x < monster_x)
                    {
                        targetX[id] = x - (int)dis(monster_x, monster_y, pr_x, pr_y);
                        if (botom_check[id])
                        {
                            if (y >= monster_y)
                                targetY[id] = y + (my_y_velo + 700);
                            else
                                targetY[id] = y + (my_y_velo + 200);
                        }
                        else
                        {
                            if (y <= monster_y)
                                targetY[id] = y + (my_y_velo - 700);
                            else
                                targetY[id] = y + (my_y_velo - 200);
                        }
                        // if (y < pr_y)
                        //     targetY[id] = y + 100;
                        // else
                        // {
                        //     targetY[id] = y - 100;
                        // }
                    }
                    else
                    {
                        targetX[id] = x + (int)dis(monster_x, monster_y, pr_x, pr_y);
                        if (botom_check[id])
                        {
                            if (y >= monster_y)
                                targetY[id] = y + (my_y_velo + 700);
                            else
                                targetY[id] = y + (my_y_velo + 200);
                        }
                        else
                        {
                            if (y <= monster_y)
                                targetY[id] = y + (my_y_velo - 700);
                            else
                                targetY[id] = y + (my_y_velo - 200);
                        }
                        // if (y < pr_y)
                        //     targetY[id] = y + 100;
                        // else
                        // {
                        //     targetY[id] = y - 100;
                        // }
                    }
                }
                
            }
            printf("MOVE %d %d %d status : %s m : %d\n", targetX[id], targetY[id], light, status, visible_monster_count);
            iter++;
        }
    }

    return 0;
}

bool check_monster(int det[100][7], int i, int vis, int *monster_id, int x, int y, int light)
{
    double d = 10000.01;
    int c = -42;
    for (; i < vis; i++)
    {
        // fprintf(stderr, "%d", id);
        if (det[i][6] == -1)
        {
            double tmp = dis((double)x,(double)y,(double)det[i][1],(double)det[i][2]);
            if (tmp < 2100 && tmp < d)
            {
                d = tmp;
                c = i;
            }
        }
    }
    if (c != -42)
        return (*monster_id = det[c][0], true);
    *monster_id = 1337;
    return false;
}

double dis(double drone_x, double drone_y, double cr_x, double cr_y)
{
    double d = sqrt(pow(drone_x - cr_x, 2) + pow(drone_y - cr_y, 2));
    return d;
}

bool if_scanned(int scansDroneById[100][100], int droneId, int fish_id)
{
    for (int i = 0; scansDroneById[droneId][i] != -42; i++)
    {
        if (scansDroneById[droneId][i] == fish_id)
            return true;
    }
    return false;
}

int scan_count(int scans[100][100], int id)
{
    int i = 0;
    for (; scans[id][i] != -42; i++)
    {
        continue;
    }
    return i;
}

// bool check_path(int monster_x, int monster_y, int my_x, int my_y, int my_x_velo, int my_y_velo)
// {
//     double x = my_x, y = my_y;
//     double magnitude = dis((double)my_x, (double)my_y, (double)(my_x + my_x_velo), (double)(my_y + my_y_velo));
//     int dx = my_x - monster_x;
//     int dy = my_y - monster_y;
//     double ux =  dx / magnitude;
//     double uy = dy / magnitude;

//     double tmp;
//     for (int i = 0; i < (int)magnitude; i++)
//     {
//         tmp = dis(x, y, monster_x, monster_y);
//         if (tmp < 600)
//         {
//             return (false);
//         }
//         x += ux;
//         y += uy;
//     }
//     return (true);
// }