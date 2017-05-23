# SoftDev::Requesting assistance

DN: Make a basic HTML form.

  


request object

     Stores information about incoming requests.

  


     Notable fields

          request.headers

               HTML headers sent from the browser

  


          request.method

               The request method (GET or POST)

  


          request.args

               The arguments in a query string from a GET request

  


          request.form

               The arguments sent in a POST request

     

          request.args and request.form are immutable dictionaries
