# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    correction.sh                                    .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: maegaspa <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/09/22 18:47:13 by maegaspa     #+#   ##    ##    #+#        #
#    Updated: 2019/09/22 18:47:16 by maegaspa    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

#!/bin/bash

DEF='\e[m'
RED='\e[1;31m'
GREEN='\e[1;32m'
BLUE='\e[1;34m'
YELLOW='\e[1;33m'
ca=carli.filler
ch=champely.filler
g=grati.filler
h=hcao.filler
s=superjeannot.filler
a=abanlin.filler
i=0

while (( i < 5 ))
do
    printf "Playing against $BLUE $ca $DEF on $YELLOW map00 $DEF\n"
    ./filler_vm -f maps/map00 -p1 players/maegaspa.filler -p2 players/$ca > log.txt
    winner=$(cat filler.trace | grep won | rev | cut -d '/' -f1 | rev)
    if [ "$winner" = "maegaspa.filler won" ]
    then
        printf "$GREEN $winner $DEF, I'm the best ma frend.\n"
    else
        printf "$RED $winner $DEF, he is the best ma frend.\n"
    fi
    printf "Playing against $BLUE $ch $DEF on $YELLOW map00 $DEF\n"
    ./filler_vm -f maps/map00 -p1 players/maegaspa.filler -p2 players/$ch > log.txt
    winner=$(cat filler.trace | grep won | rev | cut -d '/' -f1 | rev)
    if [ "$winner" = "maegaspa.filler won" ]
    then
        printf "$GREEN $winner $DEF, I'm the best ma frend.\n"
    else
        printf "$RED $winner $DEF, he is the best ma frend.\n"
    fi
    printf "Playing against $BLUE $g $DEF on $YELLOW map00 $DEF\n"
    ./filler_vm -f maps/map00 -p1 players/maegaspa.filler -p2 players/$g > log.txt
    winner=$(cat filler.trace | grep won | rev | cut -d '/' -f1 | rev)
    if [ "$winner" = "maegaspa.filler won" ]
    then
        printf "$GREEN $winner $DEF, I'm the best ma frend.\n"
    else
        printf "$RED $winner $DEF, he is the best ma frend.\n"
    fi
    printf "Playing against $BLUE $h $DEF on $YELLOW map00 $DEF\n"
    ./filler_vm -f maps/map00 -p1 players/maegaspa.filler -p2 players/$h > log.txt
    winner=$(cat filler.trace | grep won | rev | cut -d '/' -f1 | rev)
    if [ "$winner" = "maegaspa.filler won" ]
    then
        printf "$GREEN $winner $DEF, I'm the best ma frend.\n"
    else
        printf "$RED $winner $DEF, he is the best ma frend.\n"
    fi
    printf "Playing against $BLUE $s $DEF on $YELLOW map00 $DEF\n"
    ./filler_vm -f maps/map00 -p1 players/maegaspa.filler -p2 players/$s > log.txt
    winner=$(cat filler.trace | grep won | rev | cut -d '/' -f1 | rev)
    if [ "$winner" = "maegaspa.filler won" ]
    then
        printf "$GREEN $winner $DEF, I'm the best ma frend.\n"
    else
        printf "$RED $winner $DEF, he is the best ma frend.\n"
    fi
    printf "Playing against $BLUE $a $DEF on $YELLOW map00 $DEF\n"
    ./filler_vm -f maps/map00 -p1 players/maegaspa.filler -p2 players/$a > log.txt
    winner=$(cat filler.trace | grep won | rev | cut -d '/' -f1 | rev)
    if [ "$winner" = "maegaspa.filler won" ]
    then
        printf "$GREEN $winner $DEF, I'm the best ma frend.\n"
    else
        printf "$RED $winner $DEF, he is the best ma frend.\n"
    fi
    ((i+=1))
done
i=0
while (( i < 5 ))
do
    printf "Playing against $BLUE $ca $DEF on $YELLOW map01 $DEF\n"
    ./filler_vm -f maps/map01 -p1 players/maegaspa.filler -p2 players/$ca > log.txt
    winner=$(cat filler.trace | grep won | rev | cut -d '/' -f1 | rev)
    if [ "$winner" = "maegaspa.filler won" ]
    then
        printf "$GREEN $winner $DEF, I'm the best ma frend.\n"
    else
        printf "$RED $winner $DEF, he is the best ma frend.\n"
    fi
    printf "Playing against $BLUE $ch $DEF on $YELLOW map01 $DEF\n"
    ./filler_vm -f maps/map01 -p1 players/maegaspa.filler -p2 players/$ch > log.txt
    winner=$(cat filler.trace | grep won | rev | cut -d '/' -f1 | rev)
    if [ "$winner" = "maegaspa.filler won" ]
    then
        printf "$GREEN $winner $DEF, I'm the best ma frend.\n"
    else
        printf "$RED $winner $DEF, he is the best ma frend.\n"
    fi
    printf "Playing against $BLUE $g $DEF on $YELLOW map01 $DEF\n"
    ./filler_vm -f maps/map01 -p1 players/maegaspa.filler -p2 players/$g > log.txt
    winner=$(cat filler.trace | grep won | rev | cut -d '/' -f1 | rev)
    if [ "$winner" = "maegaspa.filler won" ]
    then
        printf "$GREEN $winner $DEF, I'm the best ma frend.\n"
    else
        printf "$RED $winner $DEF, he is the best ma frend.\n"
    fi
    printf "Playing against $BLUE $h $DEF on $YELLOW map01 $DEF\n"
    ./filler_vm -f maps/map01 -p1 players/maegaspa.filler -p2 players/$h > log.txt
    winner=$(cat filler.trace | grep won | rev | cut -d '/' -f1 | rev)
    if [ "$winner" = "maegaspa.filler won" ]
    then
        printf "$GREEN $winner $DEF, I'm the best ma frend.\n"
    else
        printf "$RED $winner $DEF, he is the best ma frend.\n"
    fi
    printf "Playing against $BLUE $s $DEF on $YELLOW map01 $DEF\n"
    ./filler_vm -f maps/map01 -p1 players/maegaspa.filler -p2 players/$s > log.txt
    winner=$(cat filler.trace | grep won | rev | cut -d '/' -f1 | rev)
    if [ "$winner" = "maegaspa.filler won" ]
    then
        printf "$GREEN $winner $DEF, I'm the best ma frend.\n"
    else
        printf "$RED $winner $DEF, he is the best ma frend.\n"
    fi
    printf "Playing against $BLUE $a $DEF on $YELLOW map01 $DEF\n"
    ./filler_vm -f maps/map01 -p1 players/maegaspa.filler -p2 players/$a > log.txt
    winner=$(cat filler.trace | grep won | rev | cut -d '/' -f1 | rev)
    if [ "$winner" = "maegaspa.filler won" ]
    then
        printf "$GREEN $winner $DEF, I'm the best ma frend.\n"
    else
        printf "$RED $winner $DEF, he is the best ma frend.\n"
    fi
    ((i+=1))
done
i=0
while (( i < 5 ))
do
    printf "Playing against $BLUE $ca $DEF on $YELLOW map02 $DEF\n"
    ./filler_vm -f maps/map02 -p1 players/maegaspa.filler -p2 players/$ca > log.txt
    winner=$(cat filler.trace | grep won | rev | cut -d '/' -f1 | rev)
    if [ "$winner" = "maegaspa.filler won" ]
    then
        printf "$GREEN $winner $DEF, I'm the best ma frend.\n"
    else
        printf "$RED $winner $DEF, he is the best ma frend.\n"
    fi
    printf "Playing against $BLUE $ch $DEF on $YELLOW map02 $DEF\n"
    ./filler_vm -f maps/map02 -p1 players/maegaspa.filler -p2 players/$ch > log.txt
    winner=$(cat filler.trace | grep won | rev | cut -d '/' -f1 | rev)
    if [ "$winner" = "maegaspa.filler won" ]
    then
        printf "$GREEN $winner $DEF, I'm the best ma frend.\n"
    else
        printf "$RED $winner $DEF, he is the best ma frend.\n"
    fi
    printf "Playing against $BLUE $g $DEF on $YELLOW map02 $DEF\n"
    ./filler_vm -f maps/map02 -p1 players/maegaspa.filler -p2 players/$g > log.txt
    winner=$(cat filler.trace | grep won | rev | cut -d '/' -f1 | rev)
    if [ "$winner" = "maegaspa.filler won" ]
    then
        printf "$GREEN $winner $DEF, I'm the best ma frend.\n"
    else
        printf "$RED $winner $DEF, he is the best ma frend.\n"
    fi
    printf "Playing against $BLUE $h $DEF on $YELLOW map02 $DEF\n"
    ./filler_vm -f maps/map02 -p1 players/maegaspa.filler -p2 players/$h > log.txt
    winner=$(cat filler.trace | grep won | rev | cut -d '/' -f1 | rev)
    if [ "$winner" = "maegaspa.filler won" ]
    then
        printf "$GREEN $winner $DEF, I'm the best ma frend.\n"
    else
        printf "$RED $winner $DEF, he is the best ma frend.\n"
    fi
    printf "Playing against $BLUE $s $DEF on $YELLOW map02 $DEF\n"
    ./filler_vm -f maps/map02 -p1 players/maegaspa.filler -p2 players/$s > log.txt
    winner=$(cat filler.trace | grep won | rev | cut -d '/' -f1 | rev)
    if [ "$winner" = "maegaspa.filler won" ]
    then
        printf "$GREEN $winner $DEF, I'm the best ma frend.\n"
    else
        printf "$RED $winner $DEF, he is the best ma frend.\n"
    fi
    printf "Playing against $BLUE $a $DEF on $YELLOW map02 $DEF\n"
    ./filler_vm -f maps/map02 -p1 players/maegaspa.filler -p2 players/$a > log.txt
    winner=$(cat filler.trace | grep won | rev | cut -d '/' -f1 | rev)
    if [ "$winner" = "maegaspa.filler won" ]
    then
        printf "$GREEN $winner $DEF, I'm the best ma frend.\n"
    else
        printf "$RED $winner $DEF, he is the best ma frend.\n"
    fi
    ((i+=1))
done
rm log.txt
rm filler.trace

exit 0
