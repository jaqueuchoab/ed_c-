#include "queue.hpp"
#include <iostream>

using namespace std;

// Construtor, irá auxiliar na criação de filas, inicializando as variáveis principais
Queue::Queue()
{
  // Definindo as como NULL podemos usar como critério para identificar o fim da fila
  front = NULL;
  rear = NULL;
}

Queue::~Queue()
{
  // Ponteiro temporário
  NodeType *tempPont;

  // Enquanto o elemento da vez (que está no início da fila) NÃO for igual a NULL
  while (front != NULL)
  {
    // O ponteiro temporário receberá o "endereço" de front
    tempPont = front;
    // O ponteiro front irá receber o próximo elemento da fila, que será a partir desse momento o elemento no início dela
    front = front->next;
    // Acontecerá a exclusão do antigo elemento da vez, que foi gravado no ponteiro temporário
    delete tempPont;
  }

  // Redefinindo o ponteiro do fim da lista para NULL, visto que ele já foi deletado pois em algum momento passou a ser o front;
  rear = NULL;
}

// Verificará se a fila está cheia
bool Queue::isFull() const
{
  // Criação de um ponteiro teste
  NodeType *location;

  // Tentativa de alocar mais um nó nessa fila, se a alocação for sucesso, lançará um false, ou seja, não está cheia.
  try
  {
    location = new NodeType;
    delete location;
    return false;
  }
  // Caso, no bloco anterior o return não aconteça, uma excessão será lançada indicando que houve um erro de alocação e retornando true, indicando que sim, a fila está cheia.
  catch (std::bad_alloc exception)
  {
    return true;
  }
}

// Verificará se a fila está vazia ou não, o que será caracterizado pelo retorno do valor da condição: o início da pilha é igual a nulo? se sim, a pilha está vazia
bool Queue::isEmpty() const
{
  return (front == NULL);
}

// Enfileirar elementos
void Queue::enqueue(ItemType newItem)
{
  // Verificando inicialmente se a fila está cheia, se não estiver, o processo pode ocorrer bem
  if (!isFull())
  {
    // Criando o novo nó a ser enfileirado
    NodeType *newNode;
    // Fazendo com que esse novo ponteiro receba o valor de newItem no atributo info da struct, o elemento passado por parẫmetro
    newNode->info = newItem;
    // Fazendo com que newNode tenha uma referência para o próximo que até o momento não foi definido
    newNode->next = NULL;

    // Verificando se rear (o fim da fila) é igual a nulo
    if (rear == NULL)
    {
      // Se o fim da fila é NULL, então esse nó que está sendo enfileirado é o primeiro nó da fila
      front = newNode;
    }
    else
    {
      // Se o fim da fila não é igual NULL, significa que esse nó que está sendo enfileirado não é o primeiro da fila, então ele deve estar atrás do elemento que atualmente é o do fim, por isso:
      rear->next = newNode;
    }
    // E de qualquer forma, o ponteiro rear deve apontar para esse novo nó, visto que em sequência de inserção o último nó da fila será sempre o último a sair dela. Se a fila tem apenas um nó, então o primeiro e o último nó serão o mesmo.
    rear = newNode;
  } else {
    throw "Queue is already full!";
  }
}

// Remover elemento da fila (se atentar que a função de remoção retorna o tipo de dado que a fila guarda)
ItemType Queue::dequeue() {
  // Verificando se a fila está vazia, pois se ela estiver, a operação não pode ser feita
  if(!isEmpty()) {
    // Criando ponteiro temporário
    NodeType* tempPont;
    // Fazendo com que o temporário aponte para o início da fila
    tempPont = front;
    // Criando var item do tipo ItemType (tipo que a fila guarda) e atribuindo a ela o valor guardado no front info (primeiro elemento da fila)
    ItemType item = front->info;
    // Fazendo com que front agora aponte para o elemento próximo a ele, ou seja, o próximo na fila agora se tornará o primeiro dela
    front = front->next;

    // Verificando se o primeiro elemento da fila (que agora é o elemento que sucede o antigo primeiro da fila, como foi alterado na linha anterior :) não existe, ou seja, se o próximo elemento é igual a nulo.
    if(front == NULL) {
      // Essa atribuição indicará para uma fila que contém apenas um único elemento que agora ela está totalmente vazia, atribuição necessário, visto que, quando há um único elemento na fila tanto o front quanto o rear (primeiro e último elemento da fila) apontam para o mesmo endereço de memória/mesmo nó.
      rear = NULL;
    }
    // Exclusão do ponteiro temporário que guarda a alocação do antigo primeiro elemento da fila
    delete tempPont;
    // Retornando item que foi excluído
    return item;
  } else {
    // Erro lançado se a fila estiver vazia 
    throw "Queue is empty!";
  }
}

void Queue::print() const
{
  // Ponteiro temporário 
  NodeType* tempPont = front;
  // Enquanto temporário for diferente de NULL
  while (tempPont != NULL) {
    // Imprimir o item armazenado
    cout << tempPont->info;
    // Temporário agora apontará para o próx item, até que a condição do looping seja atendida
    tempPont = tempPont->next;
  }
  cout << endl;
}