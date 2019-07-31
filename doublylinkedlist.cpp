#include "doublylinkedlist.h"
#include  <QMessageBox>
DoublyLinkedList::DoublyLinkedList(){
    First = new Node;
    First->Prev = First;
    First->Next = First;
    First->Data = "";
}

Node *DoublyLinkedList::Insert(Node *pred, QString Data){
    Node *p=new Node;
    p->Data=Data;
    if(pred==NULL){
        p->Next=First;
        p->Prev=NULL;
        if(First!=NULL)
            First->Prev=p;
        First=p;
    }else{
        p->Prev=pred;
        p->Next=pred->Next;
        pred->Next->Prev=p;
        pred->Next=p;
    }
    QByteArray ba = Data.toLatin1();
    const char *key = ba.data();
    printf("INSERT WAS CALLED & '%s' Inserted To List\n",key);
    return p;
}

void DoublyLinkedList::Delete(Node *p){
    printf("DELETE WAS CALLED.\n");
    if(p==NULL) return;
    if(p==First){
        cout<<"\n You can't delete first node ! \n";
    }else{
        p->Prev->Next=p->Next;
        p->Next->Prev=p->Prev;
        printf("THE ITEM YOU CHOOSE HAS BEEN DELETED SUCCESSFULLY FROM LIST.\n\n");
    }
    delete p;
}

Node *DoublyLinkedList::Search(QString Key){
    printf("SEARCH WAS CALLED.\n");
    Node *Cur=First->Next;
    //converting Qstring to *char
    QByteArray ba = Key.toLatin1();
    const char *key = ba.data();
    if(Cur==First)  return NULL;
    do{
        if(Cur->Data==Key) {
            QMessageBox messageBox2;
            messageBox2.setWindowTitle("FOUNDED!");
            messageBox2.setText("' "+Key+" '"+" Founded!");
            messageBox2.exec();
            printf("<< '%s' Founded! >>\n",key);
            return Cur;
        }
        Cur=Cur->Next;
    }while (Cur!=First);

    QMessageBox messageBox;
    messageBox.setWindowTitle("ERROR!");
    messageBox.setText(Key+" does not exist in the list!");
    messageBox.exec();
    printf("<< '%s' Is Not In List! >>\n",key);
    return NULL;
}

void DoublyLinkedList::Edit(Node *p, QString NewData){
    printf("EDIT WAS CALLED.\n");
    QByteArray baa = p->Data.toLatin1();
    const char *Key = baa.data();
    p->Data=NewData;
    QByteArray ba = NewData.toLatin1();
    const char *key = ba.data();


    printf("'%s' Has Been Edited To '%s'.\n",Key,key);

}





