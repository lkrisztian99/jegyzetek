select max_sulyterheles from hajo.s_hajo where nev = 'SC Nina';

select helysegnev from HAJO.s_helyseg order by helysegnev;

select * from HAJO.s_megrendeles where igenyelt_kontenerszam>5 and fizetett_osszeg>1000000;

select orszag || ', ' ||helysegnev as hely from hajo.s_helyseg;

select lower(orszag), upper(helysegnev) from hajo.s_helyseg;

select LENGTH(nev)from hajo.s_hajo order by length(nev) desc;

select helysegnev,nvl(lakossag,-1) from hajo.s_helyseg;

select replace(orszag,'ország','királyság') from hajo.s_orszag;

select ut_id,trunc(erkezesi_ido-indulasi_ido,2) from hajo.s_ut ;

select kikoto_id from hajo.s_kikoto where leiras like '%kikötõméret: közepes%';

select orszag from hajo.s_orszag where lower(orszag) like '%a%a%' and lower(orszag) not like '%a%a%a%';


select vezeteknev,keresztnev,to_char(szul_dat,'yyyy.dd.mm') as születési_datum from hajo.s_ugyfel;

select DISTINCT(hajo_tipus) from hajo.s_hajo;

select months_between(max(indulasi_ido),min(indulasi_ido)) from hajo.s_ut;

select  avg(erkezesi_ido-indulasi_ido)  from hajo.s_ut;

select to_char(min(indulasi_ido),'yyyy.mm.dd') from hajo.s_ut;

select foldresz,count(orszag) from hajo.s_orszag where foldresz is not null group by foldresz;

select kikot.kikoto_id,count(telefon) from HAJO.s_kikoto_telefon tel inner join HAJO.s_kikoto kikot
on tel.kikoto_id=kikot.kikoto_id group by kikot.kikoto_id;

select ht.nev,count(h.hajo_tipus) from hajo.s_hajo_tipus ht inner join hajo.s_hajo h
on ht.hajo_tipus_id=h.hajo_tipus group by ht.nev;

select hely.helysegnev
from hajo.s_helyseg  hely inner join HAJO.s_kikoto kikot on
hely.helyseg_id=kikot.helyseg where leiras like '%terminálterület: közepes, kikötõméret: nagy,%';

select hajo.nev from hajo.s_hajo hajo inner join hajo.s_ut ut on
hajo.hajo_id=ut.hajo where to_char(ut.indulasi_ido,'dd')=18;

select hajo.nev from hajo.s_hajo hajo inner join hajo.s_ut ut on 
hajo.hajo_id=ut.hajo where to_char(ut.indulasi_ido,'yyyy.mm.dd')='2021.09.28';

select ht.nev, count(h.hajo_id) from HAJO.s_hajo_tipus  ht inner join HAJO.s_hajo h on
ht.hajo_tipus_id=h.hajo_tipus group by ht.nev having count(h.hajo_id)>2;

select h.nev from hajo.s_hajo h inner join hajo.s_ut ut on
h.hajo_id=ut.hajo where to_char(ut.indulasi_ido,'mm') not like to_char(ut.erkezesi_ido,'mm');

select h.nev from hajo.s_hajo h inner join hajo.s_ut ut on
h.hajo_id=ut.hajo where EXTRACT(month from indulasi_ido) not like EXTRACT(month from erkezesi_ido);


select * from hajo.s_ut where (select hajo_id from hajo.s_hajo where nev='SC Nina')=hajo;

select indulasi_kikoto, erkezesi_kikoto from hajo.s_ut where hajo=(select hajo_id from hajo.s_hajo where nev='SC Magnolia');

select vezeteknev,keresztnev,helyseg from hajo.s_ugyfel where helyseg in (select helyseg_id from hajo.s_helyseg where orszag='Egyiptom');

select ut_id from hajo.s_ut where indulasi_kikoto in(
select kikoto_id from HAJO.s_kikoto where leiras like '%terminálterület: kicsi,%');


