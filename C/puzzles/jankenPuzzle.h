#ifndef JANKEN_H
#define JANKEN_H

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "puzzle.h"
#include "../helpers.h"

typedef struct Queue {
  int front, rear, size;
  unsigned capacity;
  int* array;
} Queue;

Queue * createQueue(unsigned capacity)
{
  struct Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->capacity = capacity;
  queue->front = queue->size = 0;

  queue->rear = capacity - 1;
  queue->array = (int*)malloc(queue->capacity * sizeof(int));
  return queue;
}

int isFull(Queue *queue){
  return (queue->size == queue->capacity);
}

int isEmpty(Queue *queue) {
  return (queue->size == 0);
}

void enqueue(Queue *queue, int item) {
  if (isFull(queue)){
    return;
  }
  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->array[queue->rear] = item;
  queue->size = queue->size + 1;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)){
      return INT_MIN;
    }

    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int validateChoice(int choice) {
  if (choice > 0 && choice < 4) {
    return 1;
  } else {
    return 0; 
  }
}

int winsJanken(p1Choice, p2Choice) {
  int result = abs(p1Choice - p2Choice);
  if ((p1Choice > p2Choice && result == 1) || (p1Choice < p2Choice && result == 2)) {
    return 1;
  } else {
    return 0;
  }
}

void showQueue(Queue *choicesQueue){
  printf("\n");
  for(int i = 0;i < choicesQueue->capacity; i++){ 
    printf("\nPosição: %i\tValor: %i", i, choicesQueue->array[i]);
  }
  printf("\n");
}

int defineNPCChoice(Queue *choicesQueue, int playerChoice) {
  // showQueue(choicesQueue);
  if (isFull(choicesQueue)){
    int npcChoice = dequeue(choicesQueue);
    enqueue(choicesQueue, playerChoice);
    // showQueue(choicesQueue);
    return npcChoice;
  } else {
    enqueue(choicesQueue, playerChoice);
    // showQueue(choicesQueue);
    return playerChoice;
  }
}

char * choiceName(int choice) {
  if (choice == 1) {
    return "Pedra";
  } else if (choice == 2) {
    return "Papel";
  } else if (choice == 3) {
    return "Tesoura";
  } else {
    return "Não foi possível identificar a escolha";
  }
}

int puzzleJanken() {
  int challange = 3;
  Queue *choicesQueue = createQueue(challange);
  int wins = 0;
  int looses = 0;
  int matchs = 0;
  int endsWith = 5;
  int invalidChoice = 0;
  
  do {
    clrscr();
    printf("Partida %i\nVitórias: %i\nDerrotas: %i\n\nEscolha sua próxima jogada: \nPedra: 1 \nPapel: 2 \nTesoura: 3 \n\nSua escolha: ", matchs + 1, wins, looses);
    int playerChoice = readInt();
    clrscr();
    printf("\n\nJan-Ken-Pô!\n\n");
    if (validateChoice(playerChoice)){
      int npcChoice = defineNPCChoice(choicesQueue, playerChoice);
      printf("\n<Você> O/ %s contra %s \\O <Oponente>", choiceName(playerChoice), choiceName(npcChoice));
      if (playerChoice == npcChoice) {
        printf("\n\n>> Empatou! <<");
      } else {
        int playerWined = winsJanken(playerChoice, npcChoice);
        if (playerWined) {
          printf("\n\n >> Você venceu! \\O/<<");
          wins++;
        } else {
          printf("\n\n >> Você perdeu! /O\\ <<");
          looses++;
        }
      }
    } else {
      printf("\nEscolha invalida. Por favor escolha novamente");
    }
    matchs++;
    waitForInput();
  } while(wins < endsWith && looses < endsWith);

  if(wins > looses) {
    return 1;
  } else {
    return 0;
  }
}

#endif
