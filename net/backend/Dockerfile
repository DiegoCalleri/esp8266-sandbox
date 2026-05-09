FROM node:20-alpine

WORKDIR /app

COPY package.json yarn.lock ./
COPY tsconfig.json ./
COPY src ./src

RUN yarn install

RUN yarn build

EXPOSE 3000

CMD ["node", "dist/main.js"]