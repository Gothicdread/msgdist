#include "client.h"
#include "serverHeader.h"

void addNewClient(pClient listStart, pClient newClient) {
    if(listStart == NULL) {
        newClient->next = newClient->prev = NULL;
        listStart = newClient;
        return;
    }
    
    pClient aux = listStart;
    pText msg;
    
    //aux->c_thread = malloc(sizeof(pthread_t)); //alocar memoria dinamica para thread
    //pthread_create(&aux->c_thread, NULL, receiveMsgHandler, (void*) &msg); //maybe 

    if(aux->next == NULL)
        aux->next = newClient;
    else {
        while(aux->next != NULL)
            aux = aux->next;

        aux->next = newClient;
    }
}

void removeClient(pClient client) {
    if(client == NULL || (client->next == NULL && client->prev == NULL))
        return;
    else {
        pClient Next;
        pClient Prev;
        
        if(client->next == NULL)
            Next = NULL;
        else
            Next == client->next;
        
        if(client->prev == NULL)
            Prev = NULL;
        else
            Prev = client->prev;
        
        if(Next == NULL && Prev == NULL) //Something's wrong!
            return;
        
        Prev->next = Next;
        Next->prev = Prev;
        
        //free(client->c_thread);
        free(client);
    }
}

pClient findClientByUsername(pClient listStart, char* username)
{
    if(listStart == NULL)
        return NULL;
    
    pClient aux = listStart;
    
    do
    {
        if(strcmp(aux->username, username) == 0)
            return aux;
    }
    while(aux->next != NULL);
    
    return NULL;
}

pClient findClientByPID(pClient listStart, pid_t PID)
{
    if(listStart == NULL)
        return NULL;
    
    pClient aux = listStart;
    
    do
    {
        if(aux->c_PID == PID)
            return aux;
    }
    while(aux->next != NULL);
    
    return NULL;
}

void serverBroadcastExit(pClient listStart)
{
    if(listStart == NULL)
        return;
    
    pClient aux = listStart;
    
    do {
        kill(aux->c_PID, SIGINT);
    } while(aux->next != NULL);
}

void clientSignals(int sigNum, siginfo_t *info, void* extras)
{
    
}

void getClientPid(int sigNum, siginfo_t *info, void* extras)
{
    
}