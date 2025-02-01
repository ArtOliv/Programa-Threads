# ThreadRace

Código simples no qual utiliza a biblioteca pthread para manipulação de threads.

O programa cria 100 threads que são colocadas em uma barreira e liberadas para o trabalho após todas estarem criadas. As threads contam até 10 a cada segundo, aquela que termina a contagem primeiro é a vencedora.

Na saída padrâo é impresso o pódio do top 3 threads mais rápidas.
