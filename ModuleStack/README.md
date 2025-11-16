## Integrantes 
* Condori Paye, Michael Luis

# Preguntas y respuestas
### a. ¿Cuál es la mejor implementación? Justifique.
La elección de la implementación del stack dependerá del proyecto en el que se utilice. Por ejemplo, en una aplicación destinada a almacenar los datos de un inventario, el tamaño estará acotado y no superará un límite definido. En este caso, la mejor opción sería implementar un Stack ContiguousStatic, ya que ofrece eficiencia y simplicidad cuando la capacidad es fija.
En cambio, para una aplicación en la que se deban guardar los usuarios atendidos, la cantidad puede variar de forma dinámica. En este escenario resulta más conveniente utilizar un Stack Dynamic, dado que permite ajustar su tamaño según las necesidades de la aplicación.
### b. ¿Qué cambios haría para que no haya precondiciones? ¿Qué implicancia tiene el cambio?
Que se este verificando todo el tiempo si el stack esta vacio o lleno de esta forma el usuario no tendria que estar utilizando las funciones IsEmpty IsFull para sacar o meter un elemento al stack.


### c. ¿Qué cambios haría en el diseño para que el stack sea genérico, es decir permita elementos de otros tipos que no sean int? ¿Qué implicancia tiene el cambio?
Se podria utilizar en vez de un ``StackItem`` un ``void*`` lo cual le daria versatilidad al programa (parecido a las function de Js) , el problema recairia en que tendriamos que tener màs cuidado a la hora de retornar un valor ya que tendriamos error de Type.

### d. Proponga un nuevo diseño para que el módulo pase a ser un tipo de dato, es decir, permita a un programa utilizar más de un stack.
Una forma seria definir funciones  que retorne un espacio en memoria ejemplo
```
///
typedef int StackItem;
stack_tDato *stack_create_static(size_t capacity);
stack_tDato *stack_create_dynamic(void);   

int Push(stack_tDato *s, StackItem item);   
stackItem Pop(stack_tDato *s, StackItem *out);    
int IsEmpty(const stack_tDato *s);
int IsFull(const stack_tDato *s);          
///
```
en este caso solo tendriamos que instanciar los diferentes stack y sus respectivos metodos que interiormente funcionarian de forma diferente pero respetando el tipo de dato.

# BENCHMARK

| Implementación      | Operaciones por Iteración | PUSH (ms)   | POP (ms)    |
|---------------------|---------------------------|-------------|-------------|
| **Linked Dynamic**  | 10,000                    | 10.342     | 10.699    |
|                     | 1000                       | 1.713      | 1.830      |
|                     | 100                        | 0.0106    | 0.086    |
| **Contiguous Static** | 10,000                  | 6.301    | 4.644   |
|                     | 1000                       | 0.472    | 0.864    |
|                     | 100                        | 0.042    | 0.046    |



## Espacio en memoria

**Linked Dynamic**
* Dinamico. Se asigna memoria a medida que se agregan elementos.
* Uso (para stack de int): ActualLength * 4B

**Contiguous Static:**
* Estatico. Se asigan al crear el Stack.
* Uso (para stack de int): StackSize * 4B + 4B (del top)

## Conclusiones
Se observa del analisis de las mediciones realizadas que la configuracion Contiguous Static es superior en terminos de velocidad.

La ventaja de la configuracion Linked Dynamic radica en el espacio en memoria, pudiendo ser superior en proyectos en los que se deconoce la cantidad de elementos que se cargaran a la pila, ya que ofrece mayor versatilidad a cambio de espacio en la memoria.

# Make
Se pueden crear los  crear y probar  los distintos tipos de Stack segun se necesite

* `` make all ``: Para crear ambos correr los test-dinamic test-static
* `` make test-dinamic  `` para crear enlazar y probar StackModuleLinkedDynamic con StackModuleTes
* `` make test-static  `` para crear enlazar y probar StackModuleContiguousStatic con StackModuleTes

