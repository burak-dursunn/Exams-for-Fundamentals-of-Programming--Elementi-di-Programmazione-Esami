#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node{
  int val;
  struct node *next;
}node_t;

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

void push(node_t * head, int val) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

void push_to_head(node_t ** head, int val) {
    node_t * new_node;
    new_node = malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

int remove_last(node_t * head) {
    int retval = 0;
    /* if there is only one item in the list, remove it */
    if (head->next == NULL) {
        retval = head->val;
        free(head);
        return retval;
    }

    /* get to the last node in the list */
    node_t * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    /* now current points to the last item of the list, so let's remove current->next */
    retval = current->next->val;
    free(current->next);
    current->next = NULL;
    return retval;

}

int remove_by_index(node_t ** head, int n) {
    int i = 0;
    int retval = -1;
    node_t * current = *head;
    node_t * temp_node = NULL;

    if (n == 0) {
        return pop(head);
    }

    for (int i = 0; i < n-1; i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }

    temp_node = current->next;
    retval = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);

    return retval;

}

int remove_by_value(node_t ** head, int val) {
    node_t *previous, *current;

    if (*head == NULL) {
        return -1;
    }

    if ((*head)->val == val) {
        return pop(head);
    }

    previous = current = (*head)->next;
    while (current) {
        if (current->val == val) {
            previous->next = current->next;
            free(current);
            return val;
        }

        previous = current;
        current  = current->next;
    }
    return -1;
}

void delete_list(node_t *head) {
    node_t  *current = head,
            *next = head;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
  }

int main(int argc, char *argv[]) {
  node_t * head = NULL;
  head = malloc(sizeof(node_t));
  if (head == NULL) {
      return 1;
  }

  head->val = 1;
  head->next = NULL;
  printf("Il valore inserito nella testa della lista e': %d\n", head->val);

  printf("Vuoi inserire un altro valore?\n1-Si\n2-No\n");
  int response;
  scanf("%d", &response);

  if (response == 1) {
    head->next = malloc(sizeof(node_t));
    head->next->val = 2;
    head->next->next = NULL;
    printf("Il valore inserito nella testa della lista e': %d\n", head->next->val);

  }
  printf("Gli elementi della lista sono:\n");
  print_list(head);

  printf("Vuoi inserire un altro valore?\n1-Si\n2-No\n");
  scanf("%d", &response );
  if (response == 1) {
    int newval;
    printf("Inserisci il valore che vuoi aggiungere alla lista:\n");
    scanf("%d", &newval );
    push(head,newval);
    printf("Gli elementi della lista aggiornata sono:\n");
    print_list(head);
  }

  printf("Vuoi inserire un valore in testa alla lista?\n1-Si\n2-No\n");
  scanf("%d", &response );
  if (response == 1) {
    int newhead;
    printf("Inserisci il valore che vuoi aggiungere alla lista:\n");
    scanf("%d", &newhead );
    push_to_head(&head,newhead);
    printf("Gli elementi della lista aggiornata sono:\n");
    print_list(head);
  }

  printf("Estraggo dalla testa della lista un elemento...\n");
  printf("L'elemento estratto e': %d\n", pop(&head));
  printf("Gli elementi della lista aggiornata sono:\n");
  print_list(head);

  printf("Estraggo dalla coda della lista un elemento...\n");
  printf("L'elemento estratto e': %d\n", remove_last(head));
  printf("Gli elementi della lista aggiornata sono:\n");
  print_list(head);

  printf("Aggiungo qualche elemento alla lista...\n");
  int i;
  int el;
  srand(time(NULL));
  for (i=0;i<10;i++){
    el = rand() % 100 + 1;
    push(head,el);
  }
  printf("Gli elementi della lista aggiornata sono:\n");
  print_list(head);

  printf("\nVuoi estrarre un elemento scegliendo l'indice?\n1-Si\n2-No\n");
  scanf("%d", &response );
  if (response == 1) {
    int pos;
    printf("Inserisci la posizione dell'elemento da eliminare:\n");
    scanf("%d", &pos);
    remove_by_index(&head, pos);
    printf("Gli elementi della lista aggiornata sono:\n");
    print_list(head);
  }

  printf("\nVuoi estrarre un elemento scegliendo il valore?\n1-Si\n2-No\n");
  scanf("%d", &response );
  if (response == 1) {
    int value;
    printf("Inserisci il valore dell'elemento da eliminare:\n");
    scanf("%d", &value);
    remove_by_value(&head, value);
    printf("Gli elementi della lista aggiornata sono:\n");
    print_list(head);
  }

  printf("Elimino la lista e libero la memoria...\n");
  delete_list(head);

  return 0;
}
