#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int averageTAT=0;
int averageWT=0;
int n=0;
typedef struct process{
    int number, arrTime, burstTime,CT, TAT, WT,RT;
}process;
typedef struct linked_list linked_list;

typedef struct node {
    struct node *next_node;
    process* process;
}node;

void writeProc(process* current, int i){
    printf("%d\t%d\t%d\t%d\t%d\n", i, current->number,current->CT, current->TAT,current->WT);
};

void init_node(node* node, int arrTime, int burstTime){
    node->process->burstTime=burstTime;
    node->process->arrTime=arrTime;Ы
}
struct linked_list {
    struct node *head;
    int size;
};
void giveTheNumberForProc(linked_list * list, int i){
    node *current=list->head;
    for(int j=0; j<i; j++){
        current=current->next_node;
    }
    current->process->number=i;
}
node *create_node() {
    node *n = malloc(sizeof(node));
    n->next_node = NULL;

    return n;
}

void init_linked_list(linked_list *list) {
    list->head = NULL;
    list->size = 0;
}

node *get_last_node(linked_list *self) {
    node *n = self->head;
    while (n->next_node != NULL) {
        n = n->next_node;
    }
    return n;
}

void append_node(linked_list *self, int arrTime, int burstTime) {
    if (self->size == 0) {
        self->head = create_node();
        init_node(self->head, arrTime, burstTime);
        self->size++;
    } else {
        node *n = get_last_node(self);
        node *new_node = create_node();
        n->next_node = new_node;
        init_node(new_node, arrTime, burstTime);
        self->size++;
    }
}

void insert_node(struct linked_list *self, process* process, int position) {
    if (position == self->size) {
        append_node(self, process->arrTime, process->burstTime);
        return;
    }

    if (position < self->size) {
        node *current_node = self->head;
        for (int i = 0; i < position; i++)
            current_node = current_node->next_node;
        node *next_node = current_node->next_node;
        node new_node;
        new_node.next_node = next_node;
        current_node->next_node = &new_node;
        self->size++;
    } else {
        printf("Position is out of list");
    }
}

void delete_node(struct linked_list *self, int position) {
    if (position < self->size) {
        if(position==0) {
            node* current=self->head;
            self->head=current->next_node;
        }else{
        node *current_node = self->head;
        for (int i = 0; i < position; i++)
            current_node = current_node->next_node;
        current_node->next_node = current_node->next_node->next_node;
        self->size--;
        }
    } else printf("Position is out of list");
}




void calcProcessParam(process* current) {
    int i=current->number;
    for (int j = 0; j < i; j++)
        current->WT += current->burstTime;
    current->TAT = current->WT + current->burstTime;
    averageTAT = averageTAT + current->TAT;
    averageWT += current->WT;
    current->CT = current->WT + current->arrTime+ current->burstTime;
    current->RT=current->burstTime;
}

int main() {
    printf("Write number of processes:\n");
    scanf("%d", &n);
    linked_list currentProc;
    init_linked_list(&currentProc);
    for(int i=0; i<n; i++){
        int number=i, arrTime, burstTime;
        printf("Enter the process %d arrival time\n ", i);
        scanf("%d", &arrTime);
        printf("Enter the process %d burst time\n ", i);
        scanf("%d", &burstTime);
        append_node(&currentProc,arrTime,burstTime);
        giveTheNumberForProc(&currentProc,i);
        process * curr= get_last_node(&currentProc)->process;
        calcProcessParam(curr);
    }
    int quantum, time=0;
    int finishCounter=0;
    printf("Enter the quantum time:\n");
    scanf("%d",quantum);
    while(finishCounter!=n){
        node* curr=currentProc.head;
        for(int i=0; i<n; i++){
            if(curr->process->RT>quantum){
                curr->process->RT-=quantum;
                time+=quantum;
            } else if(curr->process->RT>0) {
                time=time+curr->process->RT;
                curr->process->CT=time;
                curr->process->TAT=curr->process->CT-curr->process->arrTime;
                curr->process->WT=curr->process->TAT-curr->process->burstTime;
                averageTAT+=curr->process->TAT;
                averageWT+=curr->process->WT;
                finishCounter++;
            }

        }
    }

    printf("Average TAT=%f\nAverageWT=%f", averageTAT / n, averageWT / n);
    return 0;
}
