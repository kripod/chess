# Sakk

A feladat egy egyszerűsített sakk játék elkészítése objektum-orientált szemlélettel. A program körönként kirajzolja a játéktáblát a hozzá tartozó sor- és vonaljelölésekkel, majd kér egy bemenetet a felhasználótól, melynek segítségével beolvasható az aktív játékos által végrehajtani kívánt lépés. A bemenet formátuma a következő:

```
([bábutípus])([kiindulás])[cél]([átalakulás])
```

- `bábutípus` _(opcionális)_: A léptetni kívánt bábu angol algebrai jelölése (egy karakterrel).
  - __Lehetséges értékek:__
    - `P` _(pawn, gyalog)_
    - `N` _(knight, huszár)_
    - `B` _(bishop, futó)_
    - `R` _(rook, bástya)_
    - `Q` _(queen, vezér)_
    - `K` _(king, király)_
  - __Alapértelmezett érték:__ `P`
- `kiindulás` _(opcionális)_: A léptetni kívánt bábu kiindulási koordinátái angol algebrai jelöléssel. Kötelező megadni, amennyiben a `cél` nem határozza meg egyértelműen.
  - __Lehetséges értékek:__ `a1` - `h8`
  - __Alapértelmezett érték:__ `cél` által meghatározott, amennyiben egyértelmű
- `cél`: A léptetni kívánt bábu cél koordinátái angol algebrai jelöléssel.
  - __Lehetséges értékek:__ `a1` - `h8`
- `átalakulás`: Gyalog 8. sorra érkezése esetén annak átalakítása vezérré, huszárrá, bástyává vagy futóvá.
  - __Lehetséges értékek:__ `Q`, `N`, `R`, `B`

A feladat elkészítéséhez __nem szükséges a sakk teljes szabályrendszerének implementálása__ _(lsd.: sáncolás, ütés menet közben, patthelyzetek felismerése)_, elegendő a lényegesebb szabályok beépítése a programba:

- Bábuk léptetése a játéktáblán _(ütések lehetőségével)_
- Sakk, illetve matt felismerése

_A megoldás elkészítéséhez STL tárolók is felhasználhatók. Az elfogadott bemenettípusok a fent leírtaktól kis mértékben eltérhetnek._

## Tesztelés

A program tesztelését a mellékelt tesztvektorok segítségével végeztem el, a memóriaszivárgás-mentességet pedig [Valgrinddal](http://valgrind.org) ellenőriztem.
