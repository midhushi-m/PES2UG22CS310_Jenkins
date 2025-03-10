pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                echo 'Starting Build Stage'
                sh 'mvn clean install'
                echo 'Build Stage Successful'
            }
        }

        stage('Test') {
            steps {
                echo 'Running Tests'
                sh 'mvn test'
                echo 'Test Stage Successful'
            }
            post {
                always {
                    junit 'target/surefire-reports/*.xml'
                }
            }
        }

        stage('Deploy') {
            steps {
                echo 'Deploying Application'
                sh 'mvn deploy'
                echo 'Deployment Successful'
            }
        }
    }

    post {
        success {
            echo 'Pipeline completed successfully!'
        }
        failure {
            echo 'Pipeline failed! Check logs for errors.'
        }
    }
}
