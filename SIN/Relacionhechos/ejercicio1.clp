(deftemplate persona

	(slot nombre (type STRING))
	(slot apellido (type STRING))

	(slot color_ojos (type SYMBOL)
			 (default negros))
	(slot altura(type FLOAT)
		    (default 1.86))
	(slot edad (type INTEGER)
		   (default 22))
)
