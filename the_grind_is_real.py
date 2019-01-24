# reddit.py
from selenium import webdriver
options = webdriver.ChromeOptions()
options.binary_location = '/Applications/Google Chrome.app/Contents/MacOS/Google Chrome'
options.add_argument('window-size=800x841')
# options.add_argument('headless')
driver = webdriver.Chrome(chrome_options=options)
driver.get('https://readtheory.org/auth/login')

username = driver.find_element_by_xpath('//*[@id="username"]')
username.send_keys('14367@students.isb.ac.th')

password = driver.find_element_by_xpath('//*[@id="password"]')
password.send_keys('mhNF2PqdfjF3W')

login_click = driver.find_element_by_xpath('//*[@id="ajaxLogin"]').click()


answer_click = driver.find_element_by_xpath('//*[@class="answer-label"]').click()

submit_click = driver.find_element_by_xpath('//*[@id="presentQuizForm-answerQuestionButton"]').click()

next_quest = driver.find_element_by_xpath('//*[@id="presentQuizForm-nextQuestionButton"]').click()




# //*[@id="presentQuizForm-button"]

# Finish and Score

#https://medium.com/@stevennatera/web-scraping-with-selenium-and-chrome-canary-on-macos-fc2eff723f9e

# <div id="nextQuiz-button" class="jquery-button nextQuiz-link">Next Quiz</div>


