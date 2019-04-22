# Proiect PAO

Aplicația realizată ca proiect pentru PAO este un soft pentru administrarea abonamentelor și biletelor de transport în comun ale utilizatorilor. 

***MENȚIUNE:*** Dacă mai jos nu este explicată vreo clasă / pachet => acele clase / pachete nu au fost implementate încă sau urmează să fie explicate.

**PACHETUL MODELS**

*Clase abstracte, interfețe și enums:*

 - `interface TransportationMethod` = interfața generală din care vor fi create biletele și abonamentele. Conține 3 getteri pentru proprietățile specifice atât abonamentelor cât și biletelor: valabilitatea în zile, preț, data achiziționării;
 - `abstract class Ticket implements TransportationMethod` = clasa abstractă Ticket implementează metodele din interfața de mai sus și mai adaugă o proprietate: `int numberOfRides;`. De aici, vor fi create toate clasele concrete de tip bilet;
 - `abstract class Subscription implements TransportationMethod` = clasa abstractă Subscription implementează toate metodele din interfață și nu mai adaugă nicio proprietate în plus;
 - `enum TransportationTypes {TICKET, SUBSCRIPTION, ANY}` = această enumerare a fost creată pentru a ușura deosebirea dintre tipurile de TransportationMethods;
 
*Clase concrete:*

 - `class OneRideTicket` / `class TwoRideTicket` / `class TenRideTicket` = clasele concrete derivate din `abstract class Ticket`. În constructor, sunt inițializate valorile pentru proprietățile din `Ticket`;
 - `class OneDaySubscription` / `class OneWeekSubscription` / `class OneMonthSubscription` = clasele concrete derivate din `abstract class Subscription`. La fel ca mai sus, constructorul inițializează proprietățile;

**PACHETUL FACTORIES**

Pentru a instanția clasele din pachetul *models*, am folosit design pattern-ul *abstract factory*. Astfel, în pachetul *factories*, se află toate clasele necesare implementării acestui design pattern.

*Abstract Factory:*
 - `abstract class AbstractTransportationFactory` = clasa abstractă cu o singură metodă abstractă, care va întoarce tipul metodei de transport în funcție de parametrul de tip string;
   - `abstract TransportationMethod getTransportationMethod(String transportationType);` = această metodă va fi implementată în fiecare *factory concret*. 
  
*Factory Producer*

 - `class FactoryProducer` = clasa aceasta are o singură metodă care produce un `AbstractTransportationFactory`. În funcție de boolean-ul transmis ca parametru, acest factory poate să fie: ***TicketFactory*** sau ***SubscriptionFactory***.
   - `public static AbstractTransportationFactory getFactory (boolean ticket)` = dacă parametrul este *true*, atunci va întoarce o nouă instanță a clasei ***TicketFactory***, altfel o nouă instanță a ***Subscription Factory***.

*Concrete Factories*

Acum, urmează cele 2 factories concrete, care vor crea obiecte de un anume tip în funcție de anumiți parametri:

 - `class TicketFactory extends AbstractTransportationFactory` = implementează metoda abstractă din clasa pe care o moștenește. În funcție de parametrul de tip *String*, întoarce o anume instanță de tip *Ticket*:
 
    - `transportationType == ”one ride”` => `new OneRideTicket();`
    - `transportationType == ”two rides”` => `new TwoRideTicket();`
    - `transportationType == ”ten rides”` => `new TenRideTicket();`
    
 - `class SubscriptionFactory extends AbstractTransportationFactory` = implementează metoda abstractă din clasa pe care o moștenește. În funcție de parametrul de tip *String*, întoarce o anume instanță de tip *Subscription*:
 
    - `transportationType == ”one day”` => `new OneDaySubscription();`
    - `transportationType == ”one week”` => `new OneWeekSubscription();`
    - `transportationType == ”one month”` => `new OneMonthSubscription();`


**PACHETUL SERVICES**

În acest pachet, se află clasele care efectuează servicii. Momentan, o singură astfel de clasă este funcțională: *TransportationService*.

 - `class TransportationService` = conține o listă de obiecte de tip `TransportationMethod` (acestea vor fi de tip *Ticket* sau *Subscription*, mai exact subclasele lor) și niște metode care realizează diferite operațiuni cu acea listă:
   
   - `public void listTransportationMethods(TransportationTypes t)` = afișează toate elementele din listă care au tipul de transport la fel ca parametrul *t*. Acesta va fi un obiect de tip enum care ne spune dacă avem: *Ticket*, *Subscription* sau *Any*. Verificarea o facem în interiorul for-ului;
   - `public void updateTransportationMethods()` = iterează prin listă și verifică dacă vreun abonament / bilet a expirat și îl elimină dacă s-a întâmplat asta.
