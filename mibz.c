#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main()
{
    int playerwins = 0;
    srand(time(NULL));
    int alive = 1;
    while (alive != 0)
    {
        printf("\e[1;1H\e[2J");
        int playerlife = 50;
        int enemylife = 30;
        int playerexp = 0;
        int newexp = 0;
        printf("Proceeding to next battle!\n");
        sleep(1);
        while (playerlife > 0 && enemylife > 0)
        {
            printf("\e[1;1H\e[2J");
            printf(R"EOF(
___  ___ ___ __   __________  ____   ____  ___              
|  \/  |/ _ \\ \ / /_   _|  \/  | | | |  \/  |              
| .  . / /_\ \\ V /  | | | .  . | | | | .  . |              
| |\/| |  _  |/   \  | | | |\/| | | | | |\/| |              
| |  | | | | / /^\ \_| |_| |  | | |_| | |  | |              
\_|__|_|_| |_|/___\/\___/\_| _|_/\___/\_|__|_/ __           
|_   _| \ | /  ___|/ _ \| \ | |_   _|_   _\ \ / /           
  | | |  \| \ `--./ /_\ \  \| | | |   | |  \ V /            
  | | | . ` |`--. \  _  | . ` | | |   | |   \ /             
 _| |_| |\  /\__/ / | | | |\  |_| |_  | |   | |             
_\___/\_|_\_|____/\_|_|_|_| \_/\___/__\_/___\_/ _   _ _____ 
| ___ \/ _ \_   _|_   _| |   |  ___|___  /  _  | \ | |  ___|
| |_/ / /_\ \| |   | | | |   | |__    / /| | | |  \| | |__  
| ___ \  _  || |   | | | |   |  __|  / / | | | | . ` |  __| 
| |_/ / | | || |   | | | |___| |___./ /__\ \_/ / |\  | |___ 
\____/\_| |_/\_/   \_/ \_____|____/\_____/\___/\_| \_|____/ 
                                                                                             
)EOF");
            printf("VICTORIES: %d \n", playerwins);
            printf("You have %d life \n",playerlife);
            printf("Enemy has %d life \n", enemylife);
            printf("--------------------\n");
            int number = rand() % 20;
            if(number % 2 == 0)
            {
                number = (number + playerwins);
                printf("Player hits enemy for %d \n", number);
                enemylife = (enemylife - number);
                if (enemylife <= 0)
                {
                    printf("\e[1;1H\e[2J");
                    playerwins++;
                    printf ("You are victorious.\nYou now do +%d damage.\n", playerwins);
                }
            }
            else
            {
                printf("Enemy hits player for %d \n", number);
                playerlife = (playerlife - number);
                if (playerlife <= 0)
                {
                    printf("\e[1;1H\e[2J");
                    printf("You are dead.\nYou won %d times.\n", playerwins);
                    alive = 0;
                }
            }
            sleep(1);
        }
    }   
}
