prevod pole ["CZ020,CZ031,....] na pole objektu val/index [
  {
    "CZ0411": "1"
  },
  {
    "CZ0413": "2"
  }.... ]

v JSONata:

(
    $count($);
    $#$i.{
        $ : $string($i+1)
    }
)



A na jednoduchy objekt key:value 

{
  "CZ0411": "1",
  "CZ0413": "2",
  "CZ0412": "3",
  "CZ0422": "4"
  ....
}

pak uz staci predchazejici vysledek jen aplikovat

$merge($)
