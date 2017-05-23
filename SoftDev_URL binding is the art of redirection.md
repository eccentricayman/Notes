# SoftDev::URL binding is the art of redirection

url_for

  


     Flask function that will build the correct url for a particular function

  


     syntax: url_for(&lt;FUNCTION&gt;)

  


redirect

  


     Flask function that will redirect a call to one route to a different response.

  


     Often used in combination with url_for

     

     Example:

     

          return redirect( url_for(‘login’) )
