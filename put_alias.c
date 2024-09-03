#include "zalias.h"

void put_alias()
{
        char *alias;
        char *macro;
        int bashOrZsh;
        int fd;
        alias = calloc(255, sizeof(char));
        macro = calloc(255, sizeof(char));
        if(!alias || !macro)
            return ; 

        printf("\e[1mWhich alias would you like to add?\n");
        scanf("%s", alias);

        printf("\e[1mWhich macro would you like to add?\n");
        scanf("%s", macro);

        printf("\e[1m Do you prefer bash or zshrc\n\e[104m [1] - bash \e[49m\n\e[45m [2] - zsh  \e[49m\e\n");
        scanf("%d", &bashOrZsh);
        
        if(bashOrZsh == 1)
            fd = open(_bashrc, O_WRONLY | O_APPEND);
        if(bashOrZsh == 2)
            fd = open(_zshrc, O_RDWR);

        if(dprintf(fd, "\nalias %s='%s'", alias, macro) > 0)
        {
            printf("\e[102m Sucess alias created \e[49m\n\n");
            if(bashOrZsh == 1)
                printf("Run \e[44m source ~/.bashrc \e[49m");
            if(bashOrZsh == 2)
                printf("Run \e[44m source ~/.zshrc \e[49m");
        }
         else
            perror("Error message :");
        
} 