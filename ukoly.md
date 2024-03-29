Rozcestník na jednotlivé stránky

* RoboChat
  * [RoboChat](https://poskolak.github.io/robochat.html)

* Stelinka
  * [Chaty](https://poskolak.github.io/StelinkaChaty.html)
  * [bubliny](https://poskolak.github.io/stelinka.html)
* Andynka
  * [Chaty](https://poskolak.github.io/andy%20chaty.html)
  * [buliny](https://poskolak.github.io/andy.html)
* Nelinka
  * [Chaty](https://poskolak.github.io/nelinkaChaty.html)
  * [bubliny](https://poskolak.github.io/nelinka.html)
* Michal
  * [Živý chat](https://poskolak.github.io/michal-chats.html)
  * [Mrtvé bubliny](https://poskolak.github.io/michal.html)

------
20.5.2022
Cíl: dokončit předchozí a zbavit nás teček

![image](https://user-images.githubusercontent.com/932761/169534102-120ed65d-391c-4dc6-b0a6-73fac6fd18ef.png)
![image](https://user-images.githubusercontent.com/932761/169534203-a93b6736-4db8-44d4-8326-d46458d112f6.png)

------
6.5.2022
Cíl: naučit se mít kulaté zprávy vlevo i vpravo
1. Zprávy vertikálně odskočit (např. margin-bottom, nebo padding-bottom)
2. Liché zprávy, široké 50% a vlevo
3. Sudé zprávy, 50% a vpravo

------
8.4.2022
Cíl: připravit chaty pro projekt autíček
1. Vytvořit novou stránku __robochat.html__
2. Název chatu v levém sloupci: __Autíčka__
3. Přidat "živé" chaty, zatím všechno vlevo
4. Udělat kulaté rohy ve zprávách chatu 

------
25.3.2022
Cíl: chaty v sloupcích
1. Přesun chatů a SEND tlačítka do pravého sloupce
2. Jako bonus: kulaté rohy

------
11.3.2022
Cíl: seznámit se s živým chatem a vyzkoušet i sebe

1. Znovu zjistit co je CSS
2. Zjistit co znamená &lt;!-- --&gt;
3. Zjistit co znamená UL a LI u tagů
4. Zprovoznit chat u sebe, zatím pouze kopírovat věci mezi šipkami

------
25.2.2022
Prázdninové stylování
Cíl: aby to bylo černý, texty bílé

1. Zjistit, co je vlastně stajlování a zjistit, co znamená zkratka CSS???
2. Přečíst úvod https://www.jakpsatweb.cz/css/
3. Upravit pozadí stránky bublin i chatů na černo a texty na bílo

------
11.2.2022
Vývojářské možnosti v Chrome nebo FF

1. Naučit se pustit okno výv. nástrojů (zkratky, v menu)
2. Naučit se přepínat zobrazení pro desktop nebo simulaci mobilu
3. Opravit šířku v simulaci mobilu u chatů a mobil
4. Andy smaže obrázek nebo ho opraví

------
28.1.2022
Úvod do responzivní design

1. Přečíst [https://www.websites.cz/responzivni-design-co-je-a-jak-funguje/](https://www.websites.cz/responzivni-design-co-je-a-jak-funguje/) [https://cs.wikipedia.org/wiki/Responzivn%C3%AD_web_design](https://cs.wikipedia.org/wiki/Responzivn%C3%AD_web_design)
2. Chaty hezky zobrazit na mobilu [https://www.vzhurudolu.cz/prirucka/viewport-meta](https://www.vzhurudolu.cz/prirucka/viewport-meta)
Toto zkusit přidat do hlavičky html, tj
```
<html>
<head>
...
<meta name="viewport" content="width=device-width, initial-scale=1">
...
</head>
<body>
....
</body>
</html>
```

------
21.1.2022
Cíl je udělat CHATY a začít používat TryIt editor

1. Vyzkoušet TryIt [https://www.w3schools.com/html/tryit.asp?filename=tryhtml_images_trulli](https://www.w3schools.com/html/tryit.asp?filename=tryhtml_images_trulli)
2. Přidat stránku s chaty, inspirace
```
<!DOCTYPE html>
<html>
   <body>
      <h1><img src="https://cdn.pixabay.com/photo/2021/05/27/13/51/instagram-logo-6288194_960_720.png" width="30"> CHATY Instáče</h1>
      <table border="1">
         <tr>
            <td>
               <a href="https://www.instagram.com/">
               <img src="https://venota-com-media.r1-cz.storage.forpsicloud.cz/media/sites/116/2020/11/shottype1-540x540-21-2.jpg" height="30">
               </a>
            </td>
            <td>
               <a href="https://www.instagram.com/">
               jméno<br>
               aktivní naposledy před 10 roky...
               </a>
            </td>
            <td>rychlá fotka</td>
         </tr>
         <tr>
            <td><img src="https://venota-com-media.r1-cz.storage.forpsicloud.cz/media/sites/116/2020/11/shottype1-540x540-21-2.jpg" height="30"></td>
            <td>texty</td>
            <td>rychlá fotka</td>
         </tr>
         <tr>
            <td>fotka</td>
            <td>texty</td>
            <td>rychlá fotka</td>
         </tr>
      </table>
   </body>
</html>
```

------
7.1.2022
Cíl: Vytvořit minimálně 3 obdélníky s barveným pozadím, které mají kulaté rohy
Jak?

1. Projít návod na [michal.html](https://poskolak.github.io/michal.html)
2. Podívat se na zdrojový [kód stránky](https://github.com/Poskolak/poskolak.github.io/blob/master/michal.html)
3. Podívat se na svojí stránku andy.html, nelinka.html, stelinka.html
4. Podívat se na [návod na kulaté rohy](https://developer.mozilla.org/en-US/docs/Web/CSS/border-radius)
5. Zkusit to přidat kulaté rohy k první, druhé a třetí zprávě. Nápověda: &lt;span style=&quot;TADY BUDE NĚJAK&Yacute; NOV&Yacute; K&Oacute;D PRO ROHY UKONČEN&Yacute; STŘEDN&Iacute;KEM; display: inline-block; width: 300px; background-color: #BBB;&quot;&gt;Prvn&iacute; zpr&aacute;va&lt;/span&gt;

------
17.12.2021
1. Přihlásit se do Github.com v prohlížeči na PC nebo laptopu
2. Následně vyzkoušet editaci souborů nelinka.md a stelinka.md
3. Vytvořit HTML soubor nelinka.html / stelinka.html a napsat do nich aktuální datum a čas
4. Přidat do svého souboru text nějakého fiktivního postu
