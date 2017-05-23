# SoftDev::Web Crawling Pythons

Making and parsing a REST call in python

  


    urllib2  


      


        Library to handle urls  


      


        .urlopen(&lt;URL&gt;)

    u = urllib2.urlopen(&lt;URL&gt;)  


  


        Open a url to be read by your program.

  


        .geturl()

  


            Returns the actual url (in case of redirects)

  


        .info()

      


            Returns the http/s header information.  


  


        .read()  


  


            Returns the contents of the target webpage.

  


    json  


  


        Library to work with json data.  


  


        .loads  


        d = json.loads(&lt;STRING&gt;)  


  


                Turns a json object string into a dictionary.  


  


        .dumps(&lt;DICTIONARY&gt;)  


  


            Turns a python dictionary into a json object string.  


  

