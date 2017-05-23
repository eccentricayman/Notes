# SoftDev::Flask: Serving artisanal web pages since 2010

File Paths and the Flask Server

     When a flask app runs, the directory where the flask file exists is considered the root directory of the web server.

     Paths for files opened by the app or supporting modules should be based on that root.

  


flask_jobs/

     app.py

     utils/

          occupations.py

     data/

          occupations.csv

     static/

  


Static is for non template static pages.

  * Images
  * CSS  

  * Javascript



  


The flask web server is configured to serve pages only under the following conditions:

  1. The requested page is a route in the flask app.  

  2. The requested page/resource is in the static directory



  


All these considerations are based on using Flask’s built in webserver and are valid during development. When deploying on an existing webserver (like apache2 or nginx), these settings may be different.
