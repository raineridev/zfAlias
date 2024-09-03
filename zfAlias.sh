#!/bin/bash

# Array de opções
options=("Create aliases")

# Função para desenhar o menu
function show_menu() {
    clear
    echo -e "\e[100m afAlias CLI \e[1;93mv1.0.0 \e[39;49m"
    echo ""
    for i in "${!options[@]}"; do
        if [[ $i == $selected ]]; then
            echo -e "\e[36;1m > \e[35m${options[$i]}\e[0m"
        else
            echo "  ${options[$i]}"
        fi
    done
}

# Controle de seleção
selected=0
while true; do
    show_menu
    read -s -n 1 key
    case $key in
        $'\x1b') 
            read -s -n 2 key 
            if [[ $key == "[A" ]]; then 
                ((selected--))
                if [ $selected -lt 0 ]; then
                    selected=$((${#options[@]} - 1))
                fi
            elif [[ $key == "[B" ]]; then
                ((selected++))
                if [ $selected -ge ${#options[@]} ]; then
                    selected=0
                fi
            fi
            ;;
        "") 
            if [ "${options[$selected]}" == "Create aliases" ]; then
                 ./a.out
                break
            fi;;
    esac
done
